#include <bits/stdc++.h>

using namespace std;

using ll = long long int;

int main(void) {
    int tc;
    cin >> tc;

    while(tc--) {
        ll a, b;
        cin >> a >> b;

        ll x, y;
        x = b-a+b;
        y = a-b+a;

        if(x >= 0 && y >= 0 && x % 3 == 0 && y % 3 == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}