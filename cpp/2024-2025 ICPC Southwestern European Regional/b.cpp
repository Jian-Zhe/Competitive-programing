#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() { 
    int n, K;
    cin >> n >> K;
    set<ll> dl_s;
    map<ll, ll> cnt;
    int ddd;

    vector<ll> raw(n);
    
    for(int i=0; i<n; i++){
        cin >> ddd;
        raw[i] = ddd;
        dl_s.insert(ddd);
        cnt[ddd]++;
    }

    vector<ll> dl(dl_s.begin(), dl_s.end());

    vector<vector<ll>>cost(n, vector<ll>(n));
    /*
        cost[i][j]
      0     1        2       3     j
    0 0     100      4100    4284
    1 x     0        1600    1683
    2 x     x        0       2  
    3 x     x        x       0  
    i
    */
    n = dl.size();

    for(int j = n-1; j >= 0; --j) {
        ll len = 0;
        for(int i = j-1; i >= 0; --i) {
            len = dl[j] - dl[i];
            cost[i][j] = cost[i+1][j] + len*len*cnt[dl[i]];
        }
    }

    // for(int i = 0; i < n; ++i) {
    //     for(int j = 0; j < n; ++j) {
    //         cout << cost[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";


    // dp[i][k] = finish first i items, use k days.
    vector<vector<ll>> dp(n, vector<ll>(K+1, LLONG_MAX));
    for(int i = 0; i < n; ++i) {
        dp[i][0] = LLONG_MAX;
        dp[i][1] = cost[0][i];
    }

    vector<vector<ll>> from(n, vector<ll>(K+1));

    for(int i = 1; i < n; ++i) {
        for(int k = 2; k <= min(K, i+1); ++k) {
            // dp[i][k] = INT_MAX;
            for(int t = 0; t < i; ++t) {
                if(k-1 <= t+1 && dp[t][k-1] + cost[t+1][i] < dp[i][k]) {
                    dp[i][k] = dp[t][k-1] + cost[t+1][i];
                    from[i][k] = t;
                }
            }
        }
    }

    // for(int i = 0; i < n; ++i) {
    //     for(int k = 1; k <= K; ++k) {
    //         cout << from[i][k] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";

    // for(int i = 0; i < n; ++i) {
    //     for(int k = 1; k <= K; ++k) {
    //         cout << dp[i][k] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";

    ll x = n-1;
    ll y = min(K, n);
    vector<ll> brk;
    for(y; y > 0; y--) {
        brk.push_back(dl[x]);
        x = from[x][y];
    }

    sort(brk.begin(), brk.end());

    // for(int b : brk) {
    //     cout << b << " ";
    // }

    for(ll r : raw) {
        cout << *(lower_bound(brk.begin(), brk.end(), r)) << " ";
    }
    cout << "\n";

    return 0;
}