#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long int;
using pii = pair<ll, ll>;
 
vector<ll> child;
 
ll build_child(ll curr, ll prev, vector<vector<ll>>& adj) {

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
 
        vector<ll> arr;
        ll sum = 0;
        for(ll nei : adj[junction]) {
            ll val = child[nei];
            if(child[nei] <= child[junction]) {
                arr.push_back(child[nei]+1);
                sum += child[nei]+1;
            } else {
                arr.push_back(n - child[junction]);
                sum += n - child[junction];
            }
        }

        for(ll cs : arr) {
            curr_res += (sum - cs) * cs;
        }

        curr_res /= 2;
 
        // cout << junction << " " << curr_res << "\n";
 
        if(curr_res > best_res) {
            best_res = curr_res;
            best_junction = junction;
            best_tmp = 0;
            for(int i = 0; i < arr.size(); ++i) {
                for(int j = i + 1; j < arr.size(); ++j) {
                    best_tmp = max(best_tmp, arr[i] * arr[j]);
                }
            }
        }
    }
 
    // cout << big1 << " " << big2 << "\n";
    cout << best_res << " " << best_res - best_tmp << "\n";
 
    return 0;
}