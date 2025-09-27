#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

class DisjointSet {
    // parents
    vector<int> ps;
    vector<int> rank;

public:
    DisjointSet(int n) {
        ps.resize(n, -1);
        rank.resize(n, 1);

        for(int i = 0; i < n; ++i) {
            ps[i] = i;
        }
    }

    // return my parent
    int find(int me) {
        if(ps[me] == me) return me;
        return ps[me] = find(ps[me]);
    }

    bool connected(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        return pa == pb;
    }

    void Union(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if(pa != pb) {
            if(rank[pa] > rank[pb]) {
                ps[pb] = pa;
            } else if(rank[pa] < rank[pb]){
                ps[pa] = pb;
            } else {
                ps[pa] = pb;
                rank[pb]++;
            }
        }
    }
};


int main(void) {
    cin.tie(0) -> sync_with_stdio(false);
    int tc;
    cin >> tc;

    while(tc--) {
        int n, m1, m2;
        cin >> n >> m1 >> m2;
        DisjointSet dsu1(n);
        DisjointSet dsu2(n);

        vector<vector<int>> adj1(n);
        vector<vector<int>> adj2(n);

        int u, v;
        for(int i = 0; i < m1; ++i) {
            cin >> u >> v;
            dsu1.Union(u, v);
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }

        for(int i = 0; i < m2; ++i) {
            cin >> u >> v;
            dsu2.Union(u, v);
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }

        int res = 0;
        for(int i = 0; i < n; ++i) {
            for(j = i; j < n; ++j) {
                if(dsu2.connected(i, j) && !dsu1.connected((i, j))) {
                    dsu1.Union(i, j);
                    adj1[i].push_back(j);
                    adj1[j].push_back(i);
                    res++;
                }
            }
        }

        set<int> finished;
    }
    return 0;
}