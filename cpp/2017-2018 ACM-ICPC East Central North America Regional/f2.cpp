#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long int;
using pii = pair<ll, ll>;
 
vector<ll> child;
vector<ll> pp;
 
ll build_child(ll curr, ll prev, vector<vector<ll>>& adj) {
    pp[curr] = prev;

    ll c = 0;
    
    for(ll nei : adj[curr]) {
        if(nei != prev) {
            c += build_child(nei, curr, adj) + 1;
        }
    }
 
    child[curr] = c;
    return c;
}
 
int main(void) {
    int n;
    cin >> n;
 
    vector<pii> edge(n);
    ll maxx = 0;
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
    pp = vector<ll>(maxx+1);
 
    build_child(0, -1, adj);
 
    // for(int i = 0; i <= maxx; ++i) {
    //     cout << child[i] << " ";
    // } cout << "\n";
    
    // try
    ll best_res = 0;
    ll best_junction = -1;
    ll best_tmp = 0;
    for(int junction = 0; junction <= maxx; ++junction) {
        ll curr_res = 0;
        ll tmp = 0;
        for(int i = 0; i < adj[junction].size(); ++i) {
            for(int j = i+1; j < adj[junction].size(); ++j) {
                ll sz1 = child[adj[junction][i]] + 1;
                ll sz2 = child[adj[junction][j]] + 1;

                if(adj[junction][i] == pp[junction]) {
                    sz1 = maxx - child[junction];
                }
                
                if(adj[junction][j] == pp[junction]) {
                    sz2 = maxx - child[junction];
                }
                
                // cout << sz1 << " " << sz2 << "\n";

                curr_res += sz1 * sz2;
                tmp = max(tmp, sz1 * sz2);
            }
        }

        // cout << junction << " " << curr_res << " " << tmp << "\n\n";
 
        if(curr_res > best_res) {
            best_res = curr_res;
            best_junction = junction;
            best_tmp = tmp;
        }
    }
 
    cout << best_res << " " << best_res - best_tmp << "\n";
    return 0;
}