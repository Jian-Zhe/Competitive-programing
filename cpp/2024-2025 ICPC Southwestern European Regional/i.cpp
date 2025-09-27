#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

bool topologicalSort(vector<int>& indegree, vector<vector<int>>& to) {
    queue<int> nodes;
    vector<bool> isFinished(indegree.size());
    for(int i = 0; i < indegree.size(); ++i) {
        if(indegree[i] == 0) {
            nodes.push(i);
        }
    }

    if(nodes.size() > 1) {
        return false;
    }

    while(!nodes.empty()) {
        int curr = nodes.front(); nodes.pop();
        isFinished[curr] = true;

        // cout << curr << "set\n";

        int opened = 0;
        for(int neigh : to[curr]) {
            indegree[neigh]--;

            if(indegree[neigh] == 0) {
                nodes.push(neigh);
                opened++;

                if(opened > 1) {
                    return false;
                }
            }
        }
    }

    for(int i = 0; i < isFinished.size(); ++i) {
        // cout << i << " " << isFinished[i] << "\n";
        if(!isFinished[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n, vector<int>());
    vector<int> indeg(n, 0);
    for(int i = 0; i < n; ++i) {
        int m;
        cin >> m;

        int nei;
        for(int j = 0; j < m; ++j) {
            cin >> nei;
            adj[i].push_back(nei-1);
            indeg[nei-1]++;
        }
    }

    bool res = topologicalSort(indeg, adj);

    if(res) {
        cout << "1\n";
    } else {
        cout << "0\n";
    }

    return 0;
}