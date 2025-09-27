#include <bits/stdc++.h>

using namespace std;

int main() {
    int tc;
    cin >> tc;

    while(tc--) {
        int n;
        cin >> n;

        int maxx = 0, minn = 10001;
        int tmp;
        for(int i = 0; i < n; ++i) {
            cin >> tmp;
            maxx = max(maxx, tmp);
            minn = min(minn, tmp);
        }
        // cout << maxx << " " << minn << "\n";
        cout << (maxx - minn) * (n-1) << "\n";
    }
    return 0;
}