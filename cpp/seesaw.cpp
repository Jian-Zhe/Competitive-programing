#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long int ll;

bool take[105];

int res = INT_MAX;

void dfs(int x, const vector<vector<int>>& chg, int cnt, ll sum, ll tar) {
    
    if(x < 0) return;

    for(int i = 0; i < chg.size(); ++i) {
        if(!take[i]) {
            take[i] = true;
            cnt += 1;
            sum += chg[i][x];

            if(sum < tar) {
                dfs(x-1, chg, cnt, sum, tar);
            } else if(sum == tar) {
                res = min(res, cnt);
            }

            cnt -= 1;
            sum -= chg[i][x];
            take[i] = false;
        }
    }

    if(sum < tar) {
        dfs(x-1, chg, cnt, sum, tar);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {

        res = INT_MAX;
        memset(take, 0, 105*sizeof(bool));

        int s;
        cin >> s;
        vector<int> left(s), right(s);

        int cnt1 = 0;
        ll sum1 = 0;
        vector<int> id1;
        for(int i = 0; i < s; ++i) {
            cin >> left[i];
            if(left[i] <= 2) {
                cnt1++;
                id1.push_back(i);
            }

            sum1 += (left[i] * (i+1));
        }

        int cnt2 = 0;
        ll sum2 = 0;
        vector<int> id2;
        for(int j = 0; j < s; ++j) {
            cin >> right[j];
            if(right[j] <= 2) {
                cnt2++;
                id2.push_back(j);
            }

            sum2 += (right[j] * (j+1));
        }

        if(sum2 == sum1) {
            cout << "0\n";
            continue;
        } else if(sum1 > sum2) {
            cout << "-1\n";
            continue;
        }

        vector<vector<int>> chg(cnt1, vector<int>(cnt2));
        for(int i = 0; i < cnt1; ++i) {
            for(int j = 0; j < cnt2; ++j) {
                chg[i][j] = id1[i] + id2[j] + 2;
            }
        }

        dfs(cnt2-1, chg, 0, 0, sum2-sum1);

        if(res == INT_MAX) {
            cout << "-1\n";
        } else {
            cout << res << "\n";
        }
    }

    return 0;
}
