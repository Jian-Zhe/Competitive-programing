#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
int a, b;
int c, d;

bool path[100];
int p = -1;
bool back(int cc, int cd) {
    // cout << cc << " " << cd << "\n";
    if(cc == a && cd == b) {
        return true;
    }

    if(cc < a && cd < b) {
        return false;
    }

    if(cc < 0 || cd < 0) {
        return false;
    }

    if(cc < cd) {
        p++;
        return back(cc, cd - cc);
    } else if(cd < cc) {
        // cout << path[p] << "\n";
        p++;
        path[p] = 1;
        return back(cc - cd, cd);
    }

    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;

    while(tc--) {
        memset(path, 0, sizeof(bool) * 100);
        p = -1;
        
        cin >> a >> b >> c >> d;

        ll res = 1;

        if(back(c, d)) {
            for(int i = p; i >= 0; --i) {
                // cout << i << " " << path[i] << "\n";
                if(path[i]) {
                    res = res * 2 + 1;
                } else {
                    res *= 2;
                }
            }

            cout << res << "\n";

            // int arr[128] = {};
            // for(int i = 0; i < 128; ++i) {
            //     arr[i] = res % 10;
            //     res /= 10;
            // }

            // bool start = false;
            // for(int i = 127; i >= 0; --i) {
            //     if(!start && arr[i] == 0) {
            //         continue;
            //     }

            //     if(arr[i] != 0 && !start) start = true;
            //     if(start) {
            //         cout << arr[i];
            //     }
            // }
            // cout << "\n";
        } else {
            cout << "-1\n";
        }

    }
    return 0;
}