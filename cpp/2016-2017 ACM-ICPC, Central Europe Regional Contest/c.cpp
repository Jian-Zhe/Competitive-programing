#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

typedef pair<int, int> pii;
typedef long long int ll;

typedef pair<double,double> pt;
pt operator-(const pt &p1, const pt &p2){
    return pt(p1.F-p2.F,p1.S-p2.S);
}

double cross(pt a, pt b){
    return a.F*b.S - a.S*b.F;
}

vector<pt> getCH(vector<pt> v){
    int n = v.size();
    sort(v.begin(),v.end());
    vector<pt> hull;
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

const double pi = acos(-1);

int main(){
    int n;
    cin >> n;

    string in;
    cin >> in;

    set<pt> ps;

    for(int i = 0; i < n; ++i) {
        if(in[i] == 'S') {
            ps.insert({i, 0});
            ps.insert({i, 1});
            ps.insert({i+1, 0});
            ps.insert({i+1, 1});
        } else if(in[i] == 'T') {
            ps.insert({i, 0});
            ps.insert({i+1, 0});
            ps.insert({i+0.5, 0.8660254038});
        } else if(in[i] == 'C') {
            int div = 5000;
            for(int j = 0; j < div; ++j) {
                double rad = 2.0 * pi / div * j;
                ps.insert({i+0.5 + 0.5 * cos(rad), 0.5 + 0.5*sin(rad)});
                // cout << i+0.5 + 0.5 * cos(rad) << " " << 0.5 + 0.5*sin(rad) << "\n";
            }
        }
    }

    vector<pt> pss(ps.begin(), ps.end());

    long double res = 0;
    vector<pt> ch = getCH(pss);
    for(int i = 0; i < ch.size(); ++i) {
        pt diff = ch[i] - ch[(i+1) % ch.size()];
        res += sqrt(diff.first*diff.first + diff.second*diff.second);
    }

    cout << fixed << setprecision(8) << res << "\n";

    return 0;
}
