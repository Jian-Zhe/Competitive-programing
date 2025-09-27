#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long int ll;

const int MAXX = 21;
int p[MAXX][2000005];

void init(int n){

    for(int i=1;i<MAXX;i++){

        bool upd = false;
        for(int k=1; k<=n; k++){
            p[i][k] = p[i-1][p[i-1][k]];
            upd |= p[i][k] > 0;
        }

        if(!upd) break;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, c;
    cin >> n >> c;

    vector<ll> arr(n*2, 0);

    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
        arr[i+n] = arr[i];
    }

    int i = 0, j = -1;
    ll dsum = 0;

    while(j < 2*n) {
        while(dsum < c && j < 2*n) {
            dsum += arr[++j];
        }

        while(dsum >= c && i <= j) {
            dsum -= arr[i++];
            p[0][i] = j+2;
        }
    }
    
    init(2*n+1);

    // for(int i = 0; i < MAXX; ++i) {
    //     for(int k = 1; k <= 2*n; ++k) {
    //         cout << p[i][k] << " ";
    //     }
    //     cout << "\n";
    // }

    for(int i = 1; i <= n; ++i) {
        int res = 0;
        int k = i;
        for(int j = MAXX-1; j >= 0; --j) {
            int pp = p[j][k];
            if(pp != 0 && pp <= i+n-1) {
                k = pp;
                res |= (1 << j);
            }
        }

        cout << res << " ";
    }

    return 0;
}
