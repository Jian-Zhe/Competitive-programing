#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

int main(void) {
    cin.tie(0) -> sync_with_stdio(false);
    int tc;
    cin >> tc;

    while(tc--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        bool fail = false;
        for(int i = 0; i < n-1; ++i) {
            int m = min(a[i], a[i+1]);
            a[i] -= m, a[i+1] -= m;
            if(a[i] > a[i+1]) {
                fail = true;
                break;
            }
        }

        if(fail) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}