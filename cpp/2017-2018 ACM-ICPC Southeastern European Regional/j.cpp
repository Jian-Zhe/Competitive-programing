#include <bits/stdc++.h>

using namespace std;

using ll = long long int;

int main(void) {

    int n;
    cin >> n;

    if(n == 1) {
        cout << "Win\n";
        return 0;
    }

    vector<ll> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    if(a == vector<ll>(n, 1)) {
        if(n % 3 == 1 || n % 3 == 2) {
            cout << "Win\n";
        } else {
            cout << "Lose\n";
        }
        return 0;
    }

    if(n == 2) {
        if(a[0] == 1) {
            cout << "Win\n";
        } else {
            cout << "Lose\n";
        }
        return 0;

    } else if(n % 3 == 0) {
        if(a[n-3] == 1 && a[n-2] <= 2) {
            cout << "Win\n";
        } else {
            cout << "Lose\n";
        }
        return 0;
    } else if(n % 3 == 1) {
        if(a[n-3] == 1 && a[n-2] <= 2) {
           cout << "Win\n";
        } else {
            cout << "Lose\n";
        }
        return 0;
    } else {
        if(a[n-2] == 1) {
            cout << "Win\n";
        } else {
            cout << "Lose\n";
        }
        return 0;
    }
    return 0;
}