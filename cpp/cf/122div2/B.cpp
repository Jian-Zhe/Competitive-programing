#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

int main(void) {
    cin.tie(0) -> sync_with_stdio(0);

    int tc;
    cin >> tc;

    while(tc--) {
        int n, l, r;
        cin >> n >> l >> r;
        vector<ll> a, b;

        ll val;
        for(int i = 1; i <= n; ++i) {
            cin >> val;
            if(i >= l && i <= r) {
                a.push_back(val);
                b.push_back(val);
            } else if(i < l) {
                a.push_back(val);
            } else if(i > r) {
                b.push_back(val);
            }
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        ll sa = 0, sb = 0;
        int len = r - l + 1;
        for(int i = 0; i < len; ++i) {
            sa += a[i];
            sb += b[i];
        }

        cout << min(sa, sb) << "\n";

    }
    return 0;
}