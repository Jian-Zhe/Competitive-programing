#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

int main(void) {
    cin.tie(0) -> sync_with_stdio(0);

    int tc;
    cin >> tc;

    while(tc--) {
        ll a, b;
        cin >> a >> b;

        if(a == b && a == 1) {
            cout << "1\n";
        } else {
            cout << b-a << "\n";
        }
    }
    return 0;
}