#include <bits/stdc++.h>

using namespace std;

using ll = long long int;

using pii = pair<int, int>;

int dire[4][2] = {
    0, 0, 0, 1, 1, 1, 1, 0
};

ll qpow(ll a, ll b, ll p) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

bool is_valid(int r, int c, int x, vector<string> g) {
    for(int i = 0; i < r-1; ++i) {
        for(int j = 0; j < c-1; ++j) {
            ll sum = 0;
            for(int k = 0; k < 4; ++k) {
                int ni = i + dire[k][0];
                int nj = j + dire[k][1];

                int nni = i + dire[(k+1)%4][0];
                int nnj = j + dire[(k+1)%4][1];

                if(ni >= 0 && ni < r && nj >= 0 && nj < c && nni >=0 && nni < r && nnj >= 0 && nnj < c) {
                    sum += qpow((g[ni][nj]-'0') - (g[nni][nnj]-'0'), x, LLONG_MAX);
                }
            }

            if(sum != 0) {
                return false;
            }
        }
    }

    return true;
}

int dire2[4][2] = {
    1, 0, 0, 1, 0, -1, -1, 0
};

vector<vector<ll>> dis;
void bfs(int r, int c, int x, vector<string> g) {
    queue<pii> q;
    dis[0][0] = 0;

    q.push({0, 0});

    while(!q.empty()) {
        pii curr = q.front(); q.pop();

        for(int i = 0; i < 4; ++i) {
            int tx = curr.first + dire2[i][0];
            int ty = curr.second + dire2[i][1];

            if(tx >= 0 && tx < r && ty >= 0 && ty < c) {
                ll to_dis = qpow((g[curr.first][curr.second]-'0') - (g[tx][ty]-'0'), x, LLONG_MAX);
                if(dis[curr.first][curr.second] + to_dis < dis[tx][ty]) {
                    dis[tx][ty] = dis[curr.first][curr.second] + to_dis;
                    q.push({tx, ty});
                }
            }
        }
    }
}

int main(void) {
    cin.tie(0) -> sync_with_stdio(0);

    int r, c, x;
    cin >> r >> c >> x;

    dis = vector<vector<ll>>(r, vector<ll>(c, LLONG_MAX));

    vector<string> g(r);
    for(int i = 0; i < r; ++i) {
        cin >> g[i];
    }

    bool valid = true;
    if(!is_valid(r, c, x, g)) {
        valid = false;
    }

    if(valid) {
        bfs(r, c, x, g);
    }

    int q_num;
    cin >> q_num;

    int sx, sy, ex, ey;
    for(int i = 0; i < q_num; ++i) {
        cin >> sx >> sy >> ex >> ey;

        sx--;
        sy--;
        ex--;
        ey--;

        if(valid) {
            printf("%lld\n", -dis[sx][sy]+dis[ex][ey]);
        } else {
            printf("INVALID\n");
        }
    }


    return 0;
}