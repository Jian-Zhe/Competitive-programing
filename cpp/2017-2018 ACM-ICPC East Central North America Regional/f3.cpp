#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long int;
using pii = pair<ll, ll>;
 
vector<ll> child;
ll best_res = 0;
ll best_tmp = 0;
ll maxx = 0;
int n;

ll build_child(ll curr, ll prev, vector<vector<ll>>& adj) {
    ll c = 0;
    for(ll nei : adj[curr]) {
        if(nei != prev) {
            c += build_child(nei, curr, adj)+1;
        }
    }
 
    child[curr] = c;

    ll curr_res = 0;
    ll tmp = 0;
    for(int i = 0; i < adj[curr].size(); ++i) {
        for(int j = i+1; j < adj[curr].size(); ++j) {
            ll sz1 = child[adj[curr][i]] + 1;
            ll sz2 = child[adj[curr][j]] + 1;

            if(adj[curr][i] == prev) {
                sz1 = maxx - child[curr];
            }
            if(adj[curr][j] == prev) {
                sz2 = maxx - child[curr];
            }
            
            curr_res += (sz1 * sz2);
            tmp = max(tmp, sz1 * sz2);
        }
    }

    if(curr_res > best_res) {
        best_res = curr_res;
        best_tmp = tmp;
    }

    return child[curr];
}
 
int main(void) {
    cin >> n;
 
    vector<pii> edge(n);
    for(int i = 0; i < n; ++i) {
        cin >> edge[i].first >> edge[i].second;
        maxx = max(max(edge[i].first, edge[i].second), maxx);
    }

    assert(maxx+1 == n+1);
 
    vector<vector<ll>> adj(maxx+1);
    for(int i = 0; i < n; ++i) {
        adj[edge[i].first].push_back(edge[i].second);
        adj[edge[i].second].push_back(edge[i].first);
    }
 
    child = vector<ll>(maxx+1);
 
    build_child(0, -1, adj);
 
    cout << best_res << " " << best_res - best_tmp << "\n";
    return 0;
}