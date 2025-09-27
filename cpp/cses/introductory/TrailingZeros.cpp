#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

#define SIZE (int) (1e7 + 1)

ll zeros(ll n) {
    if(n == 0) {
        return 0;
    }

    return n/5 + zeros(n/5);
}

int main() { _
    ll n;
    cin >> n;

    cout << zeros(n) << "\n";
    return 0;
}