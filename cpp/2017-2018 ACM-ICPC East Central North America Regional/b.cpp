#include <bits/stdc++.h>

using namespace std;

using ll = long long int;

typedef double ld;

const ld eps = 1e-8;

int dcmp(ld x) {
  if(abs(x) < eps) return 0;
  else return x < 0 ? -1 : 1;
}
struct Pt {
  ld x, y;
  int id;

  Pt(ld _x=0, ld _y=0):x(_x), y(_y) {}

  Pt operator+(const Pt &a) const {
    return Pt(x+a.x, y+a.y);  }
  Pt operator-(const Pt &a) const {
    return Pt(x-a.x, y-a.y);  }
  Pt operator*(const ld &a) const {
    return Pt(x*a, y*a);  }
  Pt operator/(const ld &a) const {
    return Pt(x/a, y/a);  }
  ld operator*(const Pt &a) const {
    return x*a.x + y*a.y;  }
  ld operator^(const Pt &a) const {
    return x*a.y - y*a.x;  }
  bool operator<(const Pt &a) const {
    return x < a.x || (x == a.x && y < a.y); }
    //return dcmp(x-a.x) < 0 || (dcmp(x-a.x) == 0 && dcmp(y-a.y) < 0); }
  bool operator==(const Pt &a) const {
    return dcmp(x-a.x) == 0 && dcmp(y-a.y) == 0;  }
};
ld norm2(const Pt &a) {
  return a*a; }
ld norm(const Pt &a) {
  return sqrt(norm2(a)); }
Pt perp(const Pt &a) {
  return Pt(-a.y, a.x); }
Pt rotate(const Pt &a, ld ang) {
  return Pt(a.x*cos(ang)-a.y*sin(ang), a.x*sin(ang)+a.y*cos(ang)); }
struct Line {
  Pt s, e, v; // start, end, end-start
  ld ang;
  Line(Pt _s=Pt(0, 0), Pt _e=Pt(0, 0)):s(_s), e(_e) { v = e-s; ang = atan2(v.y, v.x); }
  bool operator<(const Line &L) const {
    return ang < L.ang;
} };

struct Circle {
  Pt o; ld r;
  Circle(Pt _o=Pt(0, 0), ld _r=0):o(_o), r(_r) {}
};

// Pt operator-(const Pt &p1, const Pt &p2){
//     return Pt(p1.x-p2.x,p1.y-p2.y);
// }

double cross(Pt a, Pt b){
    return a.x*b.y - a.y*b.x;
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

struct gter {
  bool operator() (Pt& a, const Pt& b) {
    return a.x > b.x || (a.x == b.x && a.y > b.y);
  }
};

vector<Line> tengent( const Circle& c1 , const Circle& c2 , int sign1 ){
  // sign1 = 1 for outer tang, -1 for inter tang
  vector<Line> ret;
  double d_sq = norm2( c1.o - c2.o );
  if( d_sq < eps ) return ret;
  double d = sqrt( d_sq );
  Pt v = ( c2.o - c1.o ) / d;
  double c = ( c1.r - sign1 * c2.r ) / d;
  if( c * c > 1 ) return ret;
  double h = sqrt( max( 0.0 , 1.0 - c * c ) );
  for( int sign2 = 1 ; sign2 >= -1 ; sign2 -= 2 ){
    Pt n = { v.x * c - sign2 * h * v.y ,
             v.y * c + sign2 * h * v.x };
    Pt p1 = c1.o + n * c1.r;
    Pt p2 = c2.o + n * ( c2.r * sign1 );
    if( fabs( p1.x - p2.x ) < eps and
        fabs( p1.y - p2.y ) < eps )
      p2 = p1 + perp( c2.o - c1.o );
    ret.push_back( { p1 , p2 } );
  }
  return ret;
}

int main(void) {

    cin.tie(0) -> sync_with_stdio(0);

    int resolution = 25000;

    int n;
    cin >> n;

    vector<Pt> pts(resolution*n);
    int index= 0;

    ld ang = 2.0*acos(-1.0) / resolution;
    for(int i = 0; i < n; ++i) {
        Circle c;
        cin >> c.o.x >> c.o.y >> c.r;
        c.r += 10;

        for(int j = 0; j < resolution; ++j) {
            pts[index].x = c.o.x + c.r * cos(j*ang);
            pts[index++].y = c.o.y + c.r * sin(j*ang);
        }
    }

    vector<Pt> hull = getCH(pts);

    ld res = 0;
    for(int i = 0; i < hull.size(); ++i) {
        int nxt = (i+1) % hull.size();
        res += norm(hull[i]-hull[nxt]);
    }

    cout << fixed << setprecision(12) << res << "\n";
    return 0;
}