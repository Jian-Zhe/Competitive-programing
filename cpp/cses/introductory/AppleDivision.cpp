#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

int main(void) {
    int n;
    cin >> n;
    vector<ll> arr(n, 0);
    ll sum = 0;

    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
        sum += arr[i];
    }

    ll tar = sum/2;
    if(sum & 1) {
        tar++;
    }

    unordered_set<ll> s1, s2;
    // set<ll> s;
    s1.insert(0);

    ll maxx = 0;
    for(int i = 0; i < n; ++i) {
        for(ll val : s1) {
            // cout << val << " ";
            if(val + arr[i] <= tar) {
                s2.insert(val+arr[i]);
                maxx = max(maxx, val+arr[i]);
                if(maxx == tar) {
                    break;
                }
            }
        }
        s1.insert(s2.begin(), s2.end());
        s2.clear();
    }

    cout << abs(maxx - (sum - maxx)) << "\n";
    return 0;
}