#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int ax, ay, bx, by;
int n, m;
vector<string> grid;

int dire[4][2] = {
    0, 1, 1, 0, 0, -1, -1, 0
};

bool isInGrid(int i, int j) {
    return i < n && i >= 0 && j >= 0 && j < m;
}

bool isInter(int i, int j) {
    if(isInGrid(i, j) && grid[i][j] == '.') {
        return false;
    }
    int tx, ty;
    int xcnt = 0;
    for(int k = 0; k < 4; ++k) {
        tx = dire[k][0] + i;
        ty = dire[k][1] + j;
        if(isInGrid(tx, ty) && (grid[tx][ty] == 'X' || grid[tx][ty] == 'A' || grid[tx][ty] == 'B')) {
            xcnt++;
        }
    }
    return (xcnt == 4);
}

void draw(int i, int j, char ch) {
    // cout << i << " " << j << endl;
    
    int tx, ty;
    for(int k = 0; k < 4; ++k) {
        tx = dire[k][0] + i;
        ty = dire[k][1] + j;
        if(isInGrid(tx, ty)) {
            if(grid[tx][ty] == 'X') {
                grid[tx][ty] = ch;
                draw(tx, ty, ch);
            } else if(grid[tx][ty] == 'C') {
                int ttx = tx + dire[k][0];
                int tty = ty + dire[k][1];
                if(isInGrid(ttx, tty) && grid[ttx][tty] == 'X') {
                    grid[ttx][tty] = ch;
                    draw(ttx, tty, ch);
                }
            }
        }
    }
}

int res;
int inter = 0;

vector<vector<bool>> vis;

void cnt(int x, int y, char c) {

    int tx, ty;

    vis[x][y] = true;
    if(grid[x][y] == '.') {
        grid[x][y] = c+3;
    }

    for(int k = 0; k < 4; ++k) {
        tx = dire[k][0] + x;
        ty = dire[k][1] + y;
        if(isInGrid(tx, ty)) {
            if(grid[tx][ty] == c || grid[tx][ty] == 'C' || vis[tx][ty]) {
                continue;
            } else if(grid[tx][ty] == '.') {
                grid[tx][ty] = c+3;
                res++;
                // cout << res << "\n";;
            } else if(grid[tx][ty] == 'D' && c == 'B') {
                inter++;
                res++;
                // cout << res << "\n";;
                grid[tx][ty] = 'E';
            }

            cnt(tx, ty, c);
        }
    }
}

bool isInSet(int x, int y, char c) {
    int arr[2][2] = {
        1, 0, 0, 1
    };

    int cx = x, cy = y;

    int ct[2] = {};
    for(int i = 0; i < 2; ++i) {
        cx = x; cy = y;
        while(isInGrid(cx, cy)) {
            cx += arr[i][0];
            cy += arr[i][1];
            if(isInGrid(cx, cy) && (grid[cx][cy] == c || grid[cx][cy] == 'C')) {
                ct[i]++;
            }
        }
    }

    // cout << x << " " << y << " " << ct[0] << " " << ct[1] << endl;
    if(ct[0] % 2 == 1 && ct[1] % 2 == 1) {
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    grid = vector<string>(n);
    vis = vector<vector<bool>>(n, vector<bool>(m));

    for(int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(isInter(i, j)) {
                grid[i][j] = 'C';
            } else if(grid[i][j] == 'A') {
                ax = i, ay = j;
            } else if(grid[i][j] == 'B') {
                bx = i, by = j;
            }
        }
    }

    draw(ax, ay, 'A');
    draw(bx, by, 'B');

    // cout << "\n";
    // for(int i = 0; i < n; ++i) {
    //     cout << grid[i] << "\n";
    // }
    // cout << endl;

    int a = 0, b = 0, it = 0;
    bool fin = false;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(grid[i][j] == '.' && isInSet(i, j, 'A')) {
                res = 1;
                vis = vector<vector<bool>>(n, vector<bool>(m, 0));
                cnt(i, j, 'A');
                a = res;
                fin = true;
                break;
            }
        }

        if(fin) break;
    }

    // cout << "\n";
    // for(int i = 0; i < n; ++i) {
    //     cout << grid[i] << "\n";
    // }
    // cout << endl;

    fin = false;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(grid[i][j] == '.' && isInSet(i, j, 'B')) {

                res=1;

                vis = vector<vector<bool>>(n, vector<bool>(m, 0));
                cnt(i, j, 'B');
                b = res;
                it = inter;
                fin = true;
                break;
            }
        }

        if(fin) break;
    }

    // cout << "\n";
    // for(int i = 0; i < n; ++i) {
    //     cout << grid[i] << "\n";
    // }
    // cout << endl;

    // cout << b << " " << it << "\n";
    cout << (a-it) << " " << (b-it) << " " << it << "\n";

    return 0;
}