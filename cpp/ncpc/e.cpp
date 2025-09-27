#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

int main(void) {
    cin.tie(0) ->sync_with_stdio(0);

    int tc;
    cin >> tc;

    while(tc--) {
        int k, n;
        cin >> k >> n;

        vector<int> arr(n, 0);
        int sum = 0;
        for(int i =0 ; i < n; ++i) {
            cin >> arr[i];
            sum += arr[i];
        }

        vector<bool> dp(k, 0);
        int emt = ((-sum) % k + k) % k;
        dp[emt] = 1;
        vector<int> rs;
        rs.reserve(k);
        rs.push_back(emt);

        for(int i = 0; i < n; ++i) {
            int curr;
            for(int j : rs) {
                curr = (j + 2 * arr[i]) % k;
                if(!dp[curr]) {
                    dp[curr] = 1;
                    rs.push_back(curr);

                    if(rs.size() == k) {
                        break;
                    }
                }
            }

            if(rs.size() == k) {
                break;
            }
        }
        cout << rs.size() << "\n";
    }
    return 0;
}