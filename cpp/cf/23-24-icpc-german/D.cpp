#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pii = pair<double, int>;

// 20 * 10time?
double dp[102][501] = {};

// 4, 6, 8, 12, 20
int main(void) {
    int arr[5];
    int val[5] = {4, 6, 8, 12, 20};
    int totalNum = 0;
    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4];

    totalNum += arr[0] + arr[1] + arr[2] + arr[3] + arr[4];

    int t = 1;
    for(int i = 1; i <= 500; ++i) {
        dp[0][i] = 0;
    }

    dp[0][0] = 1;

    for(int i = 0; i < 5; ++i) {
        int num = arr[i];
        int maxVal = val[i];

        // roll num times
        int end = num+t;
        for(t; t < end; ++t ) {

            for(int j = maxVal; j >= 1; --j) {

                for(int w = 500; w >= j; --w) {
                    dp[t][w] += dp[t-1][w-j] * (1/double(maxVal));
                }
            }
        }
    }

    // for(int i = 0; i < 4; ++i) {
    //     for(int j = 1; j <= 20; ++j) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    vector<pii> ps;
    for(int i = 1; i <= 500; ++i) {
        if(dp[totalNum][i] > 0) {
            ps.push_back({dp[totalNum][i], i});
        }
    }

    sort(ps.begin(), ps.end(), greater<pii>());

    for(pii p : ps) {
        cout << p.second << " ";
    }
    cout << "\n";


    return 0;
}