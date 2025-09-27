#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long int LL;
const ld eps = 1e-8;

const ld INF = 1e18;

// typedef pair<LL, LL> Pt;

// #define X first
// #define Y second



int dcmp(ld x) {
  if(abs(x) < eps) return 0;
  else return x < 0 ? -1 : 1;
}

struct Pt {
  ld X, Y;
  Pt(ld _x=0, ld _y=0):X(_x), Y(_y) {}
  Pt operator+(const Pt &a) const {
    return Pt(X+a.X, Y+a.Y);  }
  Pt operator-(const Pt &a) const {
    return Pt(X-a.X, Y-a.Y);  }
  Pt operator*(const ld &a) const {
    return Pt(X*a, Y*a);  }
  Pt operator/(const ld &a) const {
    return Pt(X/a, Y/a);  }
  ld operator*(const Pt &a) const {
    return X*a.X + Y*a.Y;  }
  ld operator^(const Pt &a) const {
    return X*a.Y - Y*a.X;  }
  bool operator<(const Pt &a) const {
    return X < a.X || (X == a.X && Y < a.Y); }
    //return dcmp(X-a.X) < 0 || (dcmp(X-a.X) == 0 && dcmp(Y-a.Y) < 0); }
  bool operator==(const Pt &a) const {
    return dcmp(X-a.X) == 0 && dcmp(Y-a.Y) == 0;  }
};

struct gter {
  bool operator() (Pt& a, const Pt& b) {
    return a.X > b.X || (a.X == b.X && a.Y > b.Y);
  }
};

/* Given a convexhull, answer querys in O(\lg N)
CH should not contain identical points, the area should
be > 0, min pair(x, y) should be listed first */
double det( const Pt& p1 , const Pt& p2 )
{ return p1.X * p2.Y - p1.Y * p2.X; }
struct Conv{
  int n;
  vector<Pt> a;
  vector<Pt> upper, lower;
  
  Conv(vector<Pt> _a) : a(_a){
    n = a.size();
    int ptr = 0;
    for(int i=1; i<n; ++i) if (a[ptr] < a[i]) ptr = i;
    for(int i=0; i<=ptr; ++i) lower.push_back(a[i]);
    for(int i=ptr; i<n; ++i) upper.push_back(a[i]);
    upper.push_back(a[0]);

    // reverse(upper.begin(), upper.end());
  }
  int sign( LL x ){ // fixed when changed to double
    return x < 0 ? -1 : x > 0; }
  pair<LL,int> get_tang(vector<Pt> &conv, Pt vec){
    int l = 0, r = (int)conv.size() - 2;
    for( ; l + 1 < r; ){
      int mid = (l + r) / 2;
      if(sign(det(conv[mid+1]-conv[mid],vec))>0)r=mid;
      else l = mid;
    }
    return max(make_pair(det(vec, conv[r]), r),
               make_pair(det(vec, conv[0]), 0));
  }
  void upd_tang(const Pt &p, int id, int &i0, int &i1){
    if(det(a[i0] - p, a[id] - p) > 0) i0 = id;
    if(det(a[i1] - p, a[id] - p) < 0) i1 = id;
  }
  void bi_search(int l, int r, Pt p, int &i0, int &i1){
    if(l == r) return;
    upd_tang(p, l % n, i0, i1);
    int sl=sign(det(a[l % n] - p, a[(l + 1) % n] - p));
    for( ; l + 1 < r; ) {
      int mid = (l + r) / 2;
      int smid=sign(det(a[mid%n]-p, a[(mid+1)%n]-p));
      if (smid == sl) l = mid;
      else r = mid;
    }
    upd_tang(p, r % n, i0, i1);
  }
  int bi_search(Pt u, Pt v, int l, int r) {
    int sl = sign(det(v - u, a[l % n] - u));
    for( ; l + 1 < r; ) {
      int mid = (l + r) / 2;
      int smid = sign(det(v - u, a[mid % n] - u));
      if (smid == sl) l = mid;
      else r = mid;
    }
    return l % n;
  }
  // 1. whether a given point is inside the CH
  bool contain(Pt p) { 
    if (p.X < lower[0].X || p.X > lower.back().X) return 0;
    int id = lower_bound(lower.begin(), lower.end(), Pt(p.X, -INF)) - lower.begin();
    if (lower[id].X == p.X) { 
      if (lower[id].Y > p.Y) return 0;
    }else if(det(lower[id-1]-p,lower[id]-p)<0)return 0;
    id = lower_bound(upper.begin(), upper.end(), Pt(p.X, INF), gter()) - upper.begin();
    if (upper[id].X == p.X) {
      if (upper[id].Y < p.Y) return 0;
    }else if(det(upper[id-1]-p,upper[id]-p)<0)return 0;
    return 1;
  }
  // 2. Find 2 tang pts on CH of a given outside point
  // return true with i0, i1 as index of tangent points
  // return false if inside CH
  bool get_tang(Pt p, int &i0, int &i1) { 
    if (contain(p)) return false;
    i0 = i1 = 0;
    int id = lower_bound(lower.begin(), lower.end(), p) - lower.begin();
    bi_search(0, id, p, i0, i1);
    bi_search(id, (int)lower.size(), p, i0, i1);
    id = lower_bound(upper.begin(), upper.end(), p) - upper.begin();
    bi_search((int)lower.size() - 1, (int)lower.size() - 1 + id, p, i0, i1);
    bi_search((int)lower.size() - 1 + id, (int)lower.size() - 1 + (int)upper.size(), p, i0, i1);
    return true;
  }
  // 3. Find tangent points of a given vector
  // ret the idx of vertex has max cross value with vec
  int get_tang(Pt vec){ 
    pair<LL, int> ret = get_tang(upper, vec);
    ret.second = (ret.second+(int)lower.size()-1)%n;
    ret = max(ret, get_tang(lower, vec));
    return ret.second;
  }
  // 4. Find intersection point of a given line
  // return 1 and intersection is on edge (i, next(i))
  // return 0 if no strictly intersection
  bool get_intersection(Pt u, Pt v, int &i0, int &i1){ 
   int p0 = get_tang(u - v), p1 = get_tang(v - u);
   if(sign(det(v-u,a[p0]-u))*sign(det(v-u,a[p1]-u))<0){
     if (p0 > p1) swap(p0, p1);
     i0 = bi_search(u, v, p0, p1);
     i1 = bi_search(u, v, p1, p0 + n);
     return 1;
   }
   return 0;
  }

  void output() {
    for(Pt& p : upper) {
      cout << p.X << " " << p.Y << "\n";
    }
    cout << "\n";
    for(Pt& p : lower) {
      cout << p.X << " " << p.Y << "\n";
    }
  }
};

double cross(Pt a, Pt b){
    return a.X*b.Y - a.Y*b.X;
}

vector<Pt> getCH(vector<Pt> v){
    int n = v.size();
    sort(v.begin(),v.end());
    vector<Pt> hull;
    for(int i=0;i<n;i++){
        while(hull.size()>1 && cross(hull.back()-hull[hull.size()-2], v[i]-hull[hull.size()-2])<0) hull.pop_back();
        hull.push_back(v[i]);
    }
    int t=hull.size();
    for(int i=n-2;i>=0;i--){
        while(hull.size()>t && cross(hull.back()-hull[hull.size()-2], v[i]-hull[hull.size()-2])<0) hull.pop_back();
        hull.push_back(v[i]);
    }
    hull.pop_back();

    return hull;
}


int main(){
  cin.tie(0) -> sync_with_stdio(false);

  vector<Pt> points;
  int n;
  cin >> n;
  ld a, b;
  for(int i = 0; i < n; ++i) {
    cin >> a >> b;
    points.push_back(Pt(a, b));
  }

  vector<Pt> ch = getCH(points);
  // sort(ch.begin(), ch.end());
  Conv convexHull(ch);

  // cout << "ch: \n";

  // for(Pt& p : ch) {
  //   cout << p.X << " " << p.Y << "\n";
  // }
  // cout << "\n";
  
  int m;
  cin >> m;

  int res = 0;
  for(int i = 0; i < m; ++i) {
    cin >> a >> b;
    Pt p(a, b);
    if(convexHull.contain(p)) {
        // cout << p.X << " " << p.Y << "\n";
        res++;
    }
  }

  // cout << "convex hull: \n";
  // convexHull.output();

  cout << res << "\n";

}
