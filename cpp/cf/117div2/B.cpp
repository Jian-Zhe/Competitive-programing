#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

bool topologicalSort(vector<int>& indegree, vector<vector<int>>& to, vector<int>& res) {
    queue<int> nodes;
    vector<bool> isFinished(indegree.size());
    for(int i = indegree.size()-1; i >= 0; --i) {
        // cout << indegree[i] << " ";
        if(indegree[i] == 0) {
            nodes.push(i);
        }
    }

    // for(int i = 0; i < indegree.size(); ++i) {
    //     // cout << indegree[i] << " ";
    //     if(indegree[i] == 0) {
    //         nodes.push(i);
    //     }
    // }

    int cnt = res.size()-1;
    while(!nodes.empty()) {
        int curr = nodes.front(); nodes.pop();
        isFinished[curr] = true;
        res[cnt--] = curr+1;
        // cout << curr << " ";
        vector<int> zero;
        for(int neigh : to[curr]) {
            indegree[neigh]--;
            if(indegree[neigh] == 0) {
                // zero.push_back(neigh);
                nodes.push(neigh);
            }
        }

        // sort(zero.begin(), zero.end());
        // for(int zzz: zero) {
        //     nodes.push(zzz);
        // }
    }

    for(bool visited : isFinished) {
        if(!visited) return false;
    }
    return true;
}
    


int main(void) {
    cin.tie(0) -> sync_with_stdio(false);
    int tc;
    cin >> tc;

    while(tc--) {
        int n;
        cin >> n;
        vector<vector<int>> to(n);
        vector<int> ig(n);
        string s;
        for(int i = 0; i < n; ++i) {
            cin >> s;
            for(int j = 0; j < n; ++j) {
                if(s[j] == '1' && i>j) {
                    to[j].push_back(i);
                    ig[i]++;
                }
            }
        }

        vector<int> res(n);
        topologicalSort(ig, to, res);

        // cout << "---\n";
        for(int i = n-1; i >= 0; --i) {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}