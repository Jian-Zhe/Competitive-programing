#include <bits/stdc++.h>
 
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
 
int main(void) {
    int n;
    cin >> n;
 
    map<int, vector<pii>> edges;
    int u, v, w;
    for(int i = 0; i < n-1; ++i) {
        cin >> u >> v >> w;
        edges[w].push_back({u, v});
    }
 
    vector<ll> dp(n+1, 1);
    for(auto p : edges) {
        map<int, ll> curr;
        for(auto [x, y] : p.second) {
            curr[x] += dp[y];
            curr[y] += dp[x];
        }
 
        for(auto [node, val] : curr) {
            dp[node] += val;
        }
    }
 
    ll res = 0;
    for(int i = 1; i <= n; ++i) {
        res += dp[i];
    }
 
    res -= n;
    cout << res << "\n";
    return 0;
}