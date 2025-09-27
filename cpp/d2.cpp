#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long int ll;

ll state[65538][205];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int D, K;
    cin >> D >> K;

    vector<int> d(D, 0);
    for(int i = 0; i < D; ++i) {
        cin >> d[i];
    }

    
    for(int i = 0; i < (1 << D); ++i) {
        for(int j = 0; j < K; ++j) {
            state[i][j] = -1;
        }
    }

    state[0][0] = 0;

    for(int i = 0; i < (1 << D); ++i) {
        for(int j = 0; j < K; ++j) {
            for(int k = 0; k < D; ++k) {
                if(i & (1 << k)) continue;

                int s = (i | (1 << k));
                int r = (j*10 + d[k]) % K;
                state[s][r] = max(state[s][r], state[i][j] * 10 + d[k]);
            }
        }
    }

    int fs = (1 << D) - 1;
    for(int i = K-1; i >= 0; --i) {
        if(state[fs][i] >= 0) {
            cout << state[fs][i] << "\n";
            break;
        }
    }

    return 0;
}
