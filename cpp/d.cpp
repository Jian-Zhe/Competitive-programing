#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long int ll;

int state[65538][205];
int from[65538][205][3];

void peak(int curr_s, int len) {
    for(int i = 0; i < len; ++i) {
        if(curr_s & (1 << i)) {
            cout << "1";
        } else {
            cout << "0";
        }
    }
    cout << "\n";
}

void dfs(int curr_s, int r, const vector<int>& d, const int& k) {
    // peak(curr_s, d.size());
    // cout << r << "\n";

    for(int i = 0; i < d.size(); ++i) {
        if(curr_s & (1 << i)) continue;

        int ns = (curr_s | (1 << i));
        int nr = (r*10 + d[i]) % k;

        // peak(ns, d.size());
        // cout << nr << "\n";
        // cout << nr << " " << state[ns][nr] << "\n";

        if(state[ns][nr] == -1) {
            // cout << "enter\n";
            state[ns][nr] = 1;
            from[ns][nr][0] = curr_s;
            from[ns][nr][1] = r;
            from[ns][nr][2] = i;

            dfs(ns, nr, d, k);
        }
    }
}

void output(int curr_s, int r, const vector<int>& d) {
    
    if(!curr_s) {
        return;
    }

    int from_s = from[curr_s][r][0];
    int from_r = from[curr_s][r][1];

    // peak(a, d.size());

    output(from_s, from_r, d);
    cout << d[from[curr_s][r][2]];
}

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
        for(int j = 0; j < 202; ++j) {
            state[i][j] = -1;
            // from[i][j] = -1;
        }
    }

    sort(d.begin(), d.end(), greater<int>());

    // for(int i = 0; i < d.size(); ++i) {
    //     cout << d[i] << " ";
    // } cout << "\n";

    dfs(0, 0, d, K);

    // cout << "dfs" << endl;

    int final_state = (1 << D) - 1;
    // peak(final_state, d.size());

    // for(int i = 0; i <= final_state; ++i) {
    //     for(int j = 0; j < K; ++j) {
    //         peak(i, d.size());
    //         cout << j << " " << state[i][j] << "\n";
    //     }
    // }

    for(int i = K-1; i >= 0; --i) {
        // cout << state[final_state][i] << ' ';
        if(state[final_state][i] != -1) {
            output(final_state, i, d);
            break;
        }
    }
    
    cout << "\n";

    return 0;
}
