#include <bits/stdc++.h>

using namespace std;

bool vis[510][5010];
int pre[510][5010][3];

void bfs(int d, int s) {
    queue<int> qx, qy;

    qx.push(0);
    qy.push(0);
    vis[0][0] = 1;

    while(!qx.empty()) {
        int x = qx.front(); qx.pop();
        int y = qy.front(); qy.pop();

        // cout << x << " " << y << "\n";

        if(x == 0 && y == s) {
            return;
        }

        for(int i = 0; i < 10; ++i) {
            int xx = (x*10 + i) % d;
            int yy = y + i;
            if(yy <= s && !vis[xx][yy]) {
                qx.push(xx);
                qy.push(yy);
                
                vis[xx][yy] = 1;

                pre[xx][yy][0] = x;
                pre[xx][yy][1] = y;
                pre[xx][yy][2] = i;
            }
        }
    }
}

void print(int x, int y) {
    // cout << x << " " << y << "\n";
    if(x == 0 && y == 0) {
        return;
    }

    print(pre[x][y][0], pre[x][y][1]);

    cout << pre[x][y][2];
}

int main(void) {
    cin.tie(0) -> sync_with_stdio(0);

    int d, s;
    cin >> d >> s;

    bfs(d, s);

    if(vis[0][s] == 0) {
        cout << "-1\n";
        return 0;
    }

    print(0, s);
    cout << "\n";

    return 0;
}