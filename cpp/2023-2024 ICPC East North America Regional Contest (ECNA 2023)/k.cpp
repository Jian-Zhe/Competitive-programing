#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int, int> pii;
typedef long long int ll;
 
using pll = pair<ll, ll>;
using pss = pair<string, string>;
 
const ll p1 = 27, p2 = 101, mod = (ll) 1e9 + 7;
 
ll pow1[25];
ll pow2[25];
 
ll hash_all(char a, char b, char c, char d, int pos, int len) {
    return a * pow1[0] + b * pow1[1] + c * pow1[2] + d * pow1[3] + pos * pow1[4] + len * pow1[5];
}
 
int main(){
    cin.tie(0) -> sync_with_stdio(0);
 
    pow1[0] = 1;
    pow2[0] = 1;
 
    for(int i = 1; i <= 22; ++i) {
        pow1[i] = pow1[i-1] * p1 % mod;
        pow2[i] = pow2[i-1] * p2 % mod;
    }
 
    int n;
    cin >> n;
 
    vector<string> ws(n);
 
    for(int i = 0; i < n; ++i) {
        cin >> ws[i];
    }
 
 
    unordered_map<ll, int> cnt;
  
    for(int i = 0; i < n-1; ++i) {
        for(int j = i+1; j < n; ++j) {
            if(ws[i].size() != ws[j].size()) continue;

            vector<int> diff;
            for(int pos = 0; pos < ws[i].size(); ++pos) {
                if(ws[i][pos] != ws[j][pos]) {
                    diff.push_back(pos);
                }
            }

            if(diff.size() != 2 || diff[0]+1 != diff[1]) {
                continue;
            }

            int a = diff[0];

            ll hv;
            if(ws[i][a] < ws[j][a]) {
                hv = hash_all(ws[i][a], ws[i][a+1], ws[j][a], ws[j][a+1], a, ws[i].size());
            } else {
                hv = hash_all(ws[j][a], ws[j][a+1], ws[i][a], ws[i][a+1], a, ws[i].size());
            }
            if(cnt.find(hv) == cnt.end()) {
                cnt[hv] = 1;
            } else {
                cnt[hv]++;
            }
        }
    }
 
    int res = 0;
    // for(auto& c1 : ans) {
    //     for(auto& c2 : c1.second) {
    //         for(auto& a : c2.second) {
    //             if(a.second == 1) {
    //                 res++;
    //             }
    //         }
    //     }
    // }

    for(auto& p : cnt) {
        if(p.second == 1) {
            res ++;
        }
    }
 
    cout << res << "\n";
 
    return 0;
}