#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

vector<vector<int>> dp;
int maxDig;
int move(int from, int step) {
    int res = from;
    for(int i = 0; i <= maxDig; ++i) {
        if(step & (1 << i)) {
            res = dp[res][i];
        }
    }
    return res;
}

int main(void) {
    cin.tie(0)->sync_with_stdio(0);

    int n, q;
    cin >> n >> q;

    maxDig = ceil(log2(n));
    dp = vector<vector<int>>(n+1, vector<int>(maxDig+1));

    vector<int> to(n+1);
    vector<vector<int>> pre(n+1);
    for(int i = 1; i <= n; ++i) {
        cin >> to[i];
        pre[to[i]].push_back(i);
        dp[i][0] = to[i];
    }

    vector<int> cyc_id(n+1, -2);
    vector<map<int, int>> cycles;
    vector<int> cyc_dist(n+1, 0);

    for(int curr = 1; curr <= n; ++curr) {
        if(cyc_id[curr] != -2) {
            continue;
        }

        vector<int> path;
        path.push_back(curr);
        cyc_id[curr] = -3;

        int at = curr;
        while(cyc_id[to[at]] == -2) {
            at = to[at];
            cyc_id[at] = -3;
            path.push_back(at);
        }

        map<int, int> cycle;
        bool inCycle = false;
        for(int p : path) {
            inCycle |= (p == to[at]);
            if(inCycle) {
                cycle[p] = cycle.size();
                cyc_id[p] = cycles.size();
            } else {
                cyc_id[p] = -1;
            }
        }
        // for(auto [node, id] : cycle) {
        //     cout << node << " " << id << "\n";
        // }
        // cout << "\n";
        cycles.push_back(cycle);
    }

    for(int curr = 1; curr <= n; ++curr) {
        // only select the tree node which is closest to cycle
        if(cyc_id[to[curr]] == -1 || cyc_id[curr] != -1) continue;

        stack<int> st;
        st.push(curr);
        cyc_dist[curr] = 1;

        while(!st.empty()) {
            int top = st.top();
            st.pop();

            cyc_dist[top] = cyc_dist[to[top]] + 1;
            // cout << top << " " << cyc_dist[to[top]]+1 << "\n";

            for(int nei : pre[top]) {
                st.push(nei);
            }
        }
    }

    // for(int i = 1; i <= n; ++i) {
    //     cout << cyc_dist[i] << " ";
    // }
    // cout << "\n";


    // init dp
    for(int i = 1; i <= maxDig; ++i) {
        for(int j = 1; j <= n; ++j) {
            dp[j][i] = dp[ dp[j][i-1] ][ i-1 ];
        }
    }

    while(q--) {
        int u, v;
        cin >> u >> v;
        int cu = cyc_id[u];
        int cv = cyc_id[v];

        // cout << cyc_id[move(u, n)] << "\n" << cyc_id[move(v, n)] << "\n";

        if(cyc_id[move(u, n)] != cyc_id[move(v, n)]) {
            cout << "-1\n";
            continue;
        }


        if(cu == -1 && cv == -1) {
            if(cyc_dist[u] < cyc_dist[v]) {
                cout << "-1\n";
                continue;
            }

            int diff = cyc_dist[u] - cyc_dist[v];
            if(move(u, diff) == v) {
                cout << diff << "\n";
            } else {
                cout << "-1\n";
            }
        } else {

            if((cu != -1) && (cv == -1)) {
                cout << "-1\n";
                continue;
            }

            int u_cyc = move(u, cyc_dist[u]);

            map<int, int>& cycle = cycles[cyc_id[v]];
            int cyc_d = 0;
            if(cycle[u_cyc] > cycle[v]) {
                cyc_d = cycle.size() - (cycle[u_cyc] - cycle[v]);
            } else {
                cyc_d = cycle[v] - cycle[u_cyc];
            }

            cout << cyc_dist[u] + cyc_d << "\n";
        }
    }


    return 0; 
}