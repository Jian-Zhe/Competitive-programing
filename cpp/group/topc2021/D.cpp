#include <bits/stdc++.h>

using namespace std;

using ll = long long int;

int main(void) {
    int n;
    cin >> n;

    double ans = 1.0/(n-1);
    
    double fix = double(n-2)/(n-1);

    ans += fix * 1.0/(n-1);

    double seat = n-1;
    double curr = 0;
    for(int i = 0; i < n-2; ++i) {
        curr = (seat-1)/seat;
        curr -= 1/seat;
        fix *= curr;
        ans += fix * 1.0/(seat-1);
        seat -= 1;
    }

    cout << ans << endl;
    return 0;
}