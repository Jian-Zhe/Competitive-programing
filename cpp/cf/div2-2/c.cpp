#include <bits/stdc++.h>

using namespace std;

int main() {
    int tc;
    cin >> tc;

    while(tc--) {
        int n;
        cin >> n;

        string s;
        cin >> s;
        s.push_back('1');

        int prev = 1;
        bool fin = false;
        for(int i = 0; i < n+1; ++i) {
            if(s[i] == '1') {
                if(prev == 1) {
                    fin = true;
                    break;
                }
                prev = 1;
            } else if(s[i] == '0') {
                prev = 0;
            }
        }

        if(fin ) {
            cout << "Yes\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}