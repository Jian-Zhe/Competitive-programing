#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pii = pair<ll, ll>;

ll pow1[1501], pow2[1501];

struct pairhash {
    inline std::size_t operator()(const std::pair<ll,ll> & v) const {
        return hash<ll>()(v.first) ^ hash<ll>()(v.second);
    }
};

ll p1 = 47, p2 = 101, mod = (ll) 1e9 + 7;

ll qpow(ll b, ll p, ll m) {
    ll res = 1;
    while(p){
        if(p & 1) res = b * res % m;
        b = b * b % m;
        p >>= 1;
    }

    return res;
}

void hash1(string str, vector<ll>& hv, ll p) {
    hv.resize(str.size()+1);
    for(int i = 0; i < str.size(); ++i) {
        hv[i+1] = ((hv[i] * p) % mod + (str[i] - 'a' + 1)) % mod;
    }
}

pii getHash(vector<ll>& hv1, vector<ll>& hv2, int a, int b, int n) {
    ll h1 = ((hv1[b+1] - (hv1[a]*pow1[b-a+1] % mod)) % mod + mod) % mod;
    ll h2 = ((hv2[b+1] - (hv2[a]*pow2[b-a+1] % mod)) % mod + mod) % mod;
    return {h1, h2};
}

int main(void) {
    cin.tie(0)->sync_with_stdio(0);
    
    pow1[0] = 1, pow2[0] = 1;
    for(int i = 1; i <= 1500; ++i) {
        pow1[i] = qpow(p1, i, mod);
        pow2[i] = qpow(p2, i, mod);
    }

    string str;
    cin >> str;

    string s;
    cin >> s;

    vector<bool> bs(26, 0);
    for(int i = 0; i < 26; ++i) {
        bs[i] = s[i] == '0';
    }

    int k;
    cin >> k;

    vector<int> bads(str.size()+1, 0);
    for(int i = 0; i < str.size(); ++i) {
        bads[i+1] = bads[i] + bs[str[i] - 'a'];
    }

    vector<ll> hv1(str.size()+1);
    vector<ll> hv2(str.size()+1);

    hash1(str, hv1, p1);
    hash1(str, hv2, p2);

    int n = str.size();

    // set<pii> res;
    unordered_set<pii, pairhash> res;
    for(int i = 0; i < n; ++i) {
        for(int j = i; j < n; ++j) {
            if(bads[j+1] - bads[i] <= k) {
                pii ha = getHash(hv1, hv2, i, j, n);
                // cout << i << " " << j << "\n";
                // cout << ha.first << " " << ha.second << "\n";
                res.insert(ha);
                // cout << str.substr(i, j-i+1) << "\n";
            }
        }
    }

    cout << res.size() << "\n";

    return 0;
}