#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

int main(void) {
    cin.tie(0) -> sync_with_stdio(false);
    int tc;
    cin >> tc;

    while(tc--) {
        int a1, a2, a3, a4, a5;
        cin >> a1 >> a2 >> a4 >> a5;
        
        map<int, int> m;
        m[a1+a2]++;
        m[a4-a2]++;
        m[a5-a4]++;

        int res = 1;
        for(auto& p : m) {
            if(p.second > res) {
                res = p.second;
            }
        }
        cout << res << "\n";
    }
    return 0;
}