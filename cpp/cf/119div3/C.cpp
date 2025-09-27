#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

int main(void) {
    cin.tie(0) -> sync_with_stdio(false);
    int tc;
    cin >> tc;

    while(tc--) {
        int n, k;
        cin >> n >> k;

        unordered_map<int, int> m;
        int t;
        for(int i = 0; i < n; ++i) {
            cin >> t;
            m[t]++;
        }

        int res = 0;
        for(auto& p : m) {
            // cout << p.first << " " << p.second << "\n";
            if(m.find(k-p.first) != m.end()) {
                res += min(m[k - p.first], p.second);
            }            
        }

        cout << res/2 << "\n";
    }
    return 0;
}