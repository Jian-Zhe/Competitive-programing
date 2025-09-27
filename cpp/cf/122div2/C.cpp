#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

struct record {
    int u;
    int rd;
    int dg;

    bool operator<(const record& r) {
        return dg == r.dg ? rd < r.rd : dg > r.dg;
    }
};

int collect(int pre, int curr, vector<record>& rs, vector<vector<int>>& adj) {
    record r;
    r.u = curr;
    r.dg = adj[curr].size();

    int dep = 0;
    for(int nei : adj[curr]) {
        if(nei != pre) {
            dep = max(dep, collect(curr, nei, rs, adj));
        }
    }
    r.rd = dep;
    rs.push_back(r);
    return dep;
}

int collect2(int curr, vector<record>& rs, vector<vector<int>>& adj, vector<bool>& vis) {
    record r;
    r.u = curr;
    r.dg = adj[curr].size();

    vis[curr] = true;

    int dep = 0;
    for(int nei : adj[curr]) {
        if(!vis[nei]) {
            dep = max(dep, collect2(nei, rs, adj, vis));
        }
    }
    r.rd = dep;
    rs.push_back(r);
    return dep;
}

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n);
    int u, v;
    for(int i = 0; i < n-1; ++i) {
        cin >> u >> v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }
    vector<record> rs;

    collect(-1, 0, rs, adj);
    sort(rs.begin(), rs.end());

    record rs0 = rs[0];
    int rm = rs0.u;
    // cout << (rs.size() == n) << "\n";
    // for(int i = 1; i < n; ++i) {
    //     if(rs[i] < rs0) {
    //         rs0 = rs[i];
    //         rm = i;
    //     }
    // }

    vector<record>().swap(rs);

    for(int i = 0; i < n; ++i) {
        if(i == rm) adj[i].clear();

        for(int j = 0; j < adj[i].size(); ++j) {
            if(adj[i][j] == rm) {
                adj[i].erase(adj[i].begin() + j);
            }
        }
    }

    vector<bool> vis(n, 0);
    vector<record> rs2;
    vis[rm] = true;
    
    for(int i = 0; i < n; ++i) {
        if(!vis[i]) {
            collect2(i, rs2, adj, vis);
        }
    }

    sort(rs2.begin(), rs2.end());
    record rs1 = rs2[0];
    // for(int i = 1; i < n; ++i) {
        
    //     if(rs2[i] < rs1) {
    //         rs1 = rs2[i];
    //     }
    // }

    cout << rs0.dg + rs1.dg - 1 << "\n";
}

int main(void) {
    cin.tie(0) -> sync_with_stdio(0);

    int tc;
    cin >> tc;

    while(tc--) {
        solve();
    }
    return 0;
}