#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int, int> pii;
typedef long long int ll;
 
using pll = pair<ll, ll>;
using pss = pair<string, string>;
 
const ll p1 = 47, p2 = 101, mod = (ll) 1e9 + 7;
 
ll pow1[25];
ll pow2[25];
 
// struct pairhash {
//     inline size_t operator()(const pair<ll,ll> & v) const {
//         return hash<ll>()(v.first) ^ hash<ll>()(v.second);
//     }
// };
 
// unordered_set<pair<ll,ll>, pairhash> res;
 
void rhash(const string& str, vector<ll>& hv, ll p) {
    // p: 47, 101, mod: 1e9+7 (ll), 4e9+7 (ull)
    // a1 * x^3 + a2 * x^2 + a3 * x + a4
    hv.resize(str.size()+1);
    for(int i = 0; i < str.size(); ++i) {
        hv[i+1] = ((hv[i] * p) % mod + (str[i] - 'a' + 1)) % mod;
    }
}
 
pii getHash(vector<ll>& hv1, vector<ll>& hv2, int a, int b) {
    // pow1[i] = p1^i
    ll h1 = ((hv1[b+1] - (hv1[a]*pow1[b-a+1] % mod)) % mod + mod) % mod;
    ll h2 = ((hv2[b+1] - (hv2[a]*pow2[b-a+1] % mod)) % mod + mod) % mod;
    return {h1, h2};
}
 
bool pairEqual(const pll& a, const pll& b) {
    return a.first == b.first && a.second == b.second;
}
 
bool isSameWithout(vector<ll>& hv1, vector<ll>& hv2, vector<ll>& hv3, vector<ll>& hv4, int a) {
    int len = hv1.size()-1;
 
    if(a == 0 && pairEqual(getHash(hv1, hv2, 2, len-1), getHash(hv3, hv4, 2, len-1))) {
        return true;
    } else if(a+1 == len-1 && pairEqual(getHash(hv1, hv2, 0, len-3), getHash(hv3, hv4, 0, len-3))) {
        return true;
    } else {
        return pairEqual(getHash(hv1, hv2,0, a-1), getHash(hv3, hv4, 0, a-1)) && pairEqual(getHash(hv1, hv2,a+2, len-1), getHash(hv3, hv4, a+2, len-1));
    }
}

ll hash2(int len, int pos) {
    return len * pow1[1] + pos * pow1[2];
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
    vector<vector<ll>> hv1(n);
    vector<vector<ll>> hv2(n);
 
    for(int i = 0; i < n; ++i) {
        cin >> ws[i];
        rhash(ws[i], hv1[i], p1);
        rhash(ws[i], hv2[i], p2);
    }
  
    unordered_map<string, unordered_map<string, unordered_map<int, int>>> ans;
  
    for(int i = 0; i < n; ++i) {
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
 
            if(ws[i][a] != ws[j][a] && ws[i][a+1] != ws[j][a+1] && isSameWithout(hv1[i], hv2[i], hv1[j], hv2[j], a)) {
                string clue1 = ws[i].substr(a, 2);
                string clue2 = ws[j].substr(a, 2);
                
                if(clue2 < clue1) {
                    string tmp = clue1;
                    clue1 = clue2;
                    clue2 = tmp;
                }
                ll hv = hash2(ws[i].size(), a);
                if(ans.find(clue1) == ans.end() || ans[clue1].find(clue2) == ans[clue1].end() || ans[clue1][clue2].find(hv) == ans[clue1][clue2].end()) {
                    ans[clue1][clue2][hv] = 1;
                } else {
                    ans[clue1][clue2][hv]++;
                }
            }
        }
    }
 
    int res = 0;
    for(auto& c1 : ans) {
        for(auto& c2 : c1.second) {
            for(auto& a : c2.second) {
                if(a.second == 1) {
                    res++;
                }
            }
        }
    }
 
    cout << res << "\n";
 
    return 0;
}