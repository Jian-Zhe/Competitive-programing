#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

int main(void) {
    ll n; 
    cin >> n;

    ll curr = 0;
    ll res = 1;

    for(int len = 1; len <= 10; ++len) {
        curr *= 10;
        curr += 1;
        
        bool end = false;
        for(int i = 1; i <= 9; ++i) {
            ll tmp = curr * i;
            if(n >= tmp) {
                res++;
            } else {
                end = true;
                break;
            }
        }
        if(end) break;
    }

    curr = 10;
    for(int i = 2; i <= 10; ++i) {
        curr *= 10;
        if(n >= curr) {
            res++;
        }
    }

    cout << res << "\n";
    return 0;
}