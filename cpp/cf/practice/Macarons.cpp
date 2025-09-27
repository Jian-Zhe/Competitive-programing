// #pragma GCC optimize("O3")

#include <bits/stdc++.h>

using namespace std;

using ll = long long int;

const ll mod = (ll) 1e9;

struct matrix{
    ll mat[257][257];
    int n, m;
    matrix(int _n = 257, int _m = 257){
        n = _n, m = _m;
        memset(mat, 0, sizeof(mat));
    }
};

void mul(const matrix& a, const matrix& b, matrix& ret){
    for(int i=0;i<a.n;i++){
        for(int j=0;j<b.m;j++){
            ret.mat[i][j] = 0;
            for(int k=0;k<a.m;k++){
                ret.mat[i][j] += (a.mat[i][k] * b.mat[k][j]) % mod;
                ret.mat[i][j] %= mod;
            }
        }
    }
}

matrix f, ret, f2, ret2;
void fillTable(int n, int i, int prev, int curr) {
    if(i > n) {
        return;
    }

    if(n == i) {
        // cout << prev << " " << curr << "\n";
        f.mat[curr][prev]++;
        if(curr != prev) {
            f.mat[prev][curr]++;
        }
    }

    if((prev & (1 << i)) && (curr & (1 << i))) {
        
        return;

    } else if((prev & (1 << i)) || (curr & (1 << i))) {
        // has filled
        fillTable(n, i+1, prev, curr);
    } else {

        if((curr & (1 << i)) == 0 ) {

            // 1x1
            fillTable(n, i+1, prev, curr);

            // 1x2
            // fillTable(n, i+1, prev, curr | (1 << i));
        }
        
        if(i+1 < n 
            && (curr & (1 << i)) == 0 
            && (curr & (1 << i+1)) == 0
            && (prev & (1 << i+1)) == 0
        ) {
            // 2x1
            fillTable(n, i+2, prev, curr);
        }        
    }
}

int main(void) {
    ll n, m;
    cin >> n >> m;

    int end = (1 << n) - 1;
    ret.n = end+1;
    ret.m = 1;

    ret2.m = 1;

    f.n = end+1;
    f.m = end+1;

    for(int i = 0; i <= end; ++i) {
        ret.mat[i][i] = 1;
        ret2.mat[i][i] = 1;
        for(int j = 0; j <= i; ++j) {
            fillTable(n, 0, i, j);
        }
    }

    // for(int i = 0; i <= end; ++i) {
    //     for(int j = 0; j <= end; ++j) {
    //         cout << f1.mat[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";

    matrix *p1 = &ret, *p2 = &ret2, *fp1 = &f, *fp2 = &f2, *tmp;
    while(m) {
        if(m & 1) {
            mul(*fp1, *p1, *p2);
            tmp = p1; p1 = p2; p2 = tmp;
        }
        
        mul(*fp1, *fp1, *fp2);
        m >>= 1;

        tmp = fp1; fp1 = fp2; fp2 = tmp;
    }

    cout << p1->mat[0][0] << "\n";

    return 0;
}