#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

int main() { _
    ofstream out("dpmem.txt");

    int tc;
    cin >> tc;
    out << std::hex <<"0x"<< long(&tc) << "\n";

    while(tc--) {
    out << std::hex <<"0x"<< long(&tc) << "\n";

    string a, b;
    cin >> b >> a;

    out << std::hex <<"0x"<< long(a.data()) << "\n";
    out << std::hex <<"0x"<< long(b.data()) << "\n";


    int len1 = a.length();
    int len2 = b.length();

    out << std::hex <<"0x"<< long(&len1) << "\n";
    out << std::hex <<"0x"<< long(&len2) << "\n";

    vector<vector<ll>> dp(5001, vector<ll>(5001));
    for(int i = 0; i < len1+10; ++i) {
        for(int j = 0; j < len2+10; ++j) {
            out << &dp[i][j] << "\n";
        }
    }

    out << std::hex <<"0x"<< long(&len1) << "\n";
    out << std::hex <<"0x"<< long(&len2) << "\n";

    for(int i = 1; i <= len2; ++i) {
        dp[0][i] = i;
        out << &dp[0][i] << "\n";
    }

    for(int i = 1; i <= len1; ++i) {
        dp[i][0] = i;
        out << &dp[i][0] << "\n";
    }

    for(int i = 1; i <= len1; ++i) {
        for(int j = 1; j <= len2; ++j) {
            out << std::hex <<"0x"<< long(&a[i-1]) << "\n";
            out << std::hex <<"0x"<< long(&a[i-1]) << "\n";

            if(a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
                out << &dp[i][j] << "\n";
                out << &dp[i-1][j-1] << "\n";
            } else {
                dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                out << &dp[i][j] << "\n";
                out << &dp[i-1][j] << "\n";
                out << &dp[i][j-1] << "\n";
                out << &dp[i-1][j-1] << "\n";
            }
        }
    }

    cout << dp[len1][len2] << "\n";
    out << std::hex <<"0x"<< long(&len1) << "\n";
    out << std::hex <<"0x"<< long(&len2) << "\n";    
    out << &dp[len1][len2] << "\n";

    }
    return 0;
}