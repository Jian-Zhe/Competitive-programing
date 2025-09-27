#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

int main(void) {
    cin.tie(0) -> sync_with_stdio(false);
    int tc;
    cin >> tc;

    while(tc--) {
        int n, m;
        cin >> n >> m;
        unordered_map<int, int> owner;
        for(int i = 1; i <= n; ++i) {
            int card ;
            for(int j = 0; j < m; ++j) {
                cin >> card;
                owner[card] = i;
            }
        }

        vector<int> p(n);
        set<int> ps;
        for(int i = 0; i < n; ++i) {
            p[i] = owner[i];
            ps.insert(owner[i]);
        }

        if(ps.size() != n) {
            // for(int i = 0; i < n; ++i) {
            //     cout << p[i] << " ";
            // }
            // cout << "\n";
            cout << "-1\n";
            continue;
        } else {
            bool fail = false;
            for(int i = n; i < n*m; ++i) {
                if(owner[i] != p[i % n]) {
                    fail = true;
                    break;
                }
            }

            if(fail) {
                cout << "-1";
            } else {
                for(int i = 0; i < n; ++i) {
                    cout << p[i] << " ";
                }
            }
        }
        cout << "\n";
    }
    return 0;
}