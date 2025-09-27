#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

int pa[200002][31] = {};

int main(void) {
    cin.tie(0) -> sync_with_stdio(0);
    int n, q;
    cin >> n >> q;

    for(int i = 1; i <= n; ++i) {
        cin >> pa[i][0];
    }

    for(int i = 1; i <= 30; ++i) {
        for(int node = 1; node <= n; ++node) {
            pa[node][i] = pa[pa[node][i-1]][i-1];
        }
    }

    int x, k;
    while(q--) {
        cin >> x >> k;
        
        int res = x;
        for(int i = 0; i < 32; ++i) {
            if(k & (1 << i)) {
                res = pa[res][i];
            }
        }

        cout << res << "\n";
    }

    return 0;
}
