#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

ll fac[1000001], inv[1000001];

ll mod = 1000000007;

ll qpow(ll x, ll y){
    ll sum = 1;
    while(y > 0){
        if(y & 1){
            sum = sum*x%mod;
        }
        y >>= 1;
        x = x*x%mod;
    }
    return sum;
}

int main(void) {
    cin.tie(0)->sync_with_stdio(0);

    fac[0] = fac[1] = 1;
    inv[0] = inv[1] = 1;
    for(int i = 2; i <= 1000000; ++i) {
        fac[i] = (fac[i-1] * i) % mod;
        inv[i] = qpow(fac[i], mod-2);
    }

    int n;
    cin >> n;

    ll a, b;
    while(n--) {
        cin >> a >> b;
        ll res = fac[a] * inv[b] % mod;
        res = res * inv[a-b] % mod;
        cout << res << '\n';
    }
    return 0;
}