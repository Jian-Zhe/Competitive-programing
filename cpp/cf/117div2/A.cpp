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

        int res = 4*m;
        int x, y;
        for(int i = 0; i < n; ++i) {
            cin >> x >> y;
            if(i != 0)
                res += 2*x + 2*y;
        }
        cout << res << "\n";
    }
    
    return 0;
}