struct pairhash {
    inline size_t operator()(const pair<ll,ll> & v) const {
        return hash<ll>()(v.first) ^ hash<ll>()(v.second);
    }
};

unordered_set<pair<ll,ll>, pairhash> res;

void rhash(string str, vector<ll>& hv, ll p) {
    // p: 47, 101, mod: 1e9+7 (ll), 4e9+7 (ull)
    // a1 * x^3 + a2 * x^2 + a3 * x + a4
    hv.resize(str.size()+1);
    for(int i = 0; i < str.size(); ++i) {
        hv[i+1] = ((hv[i] * p) % mod + (str[i] - 'a' + 1)) % mod;
    }
}

pii getHash(vector<ll>& hv1, vector<ll>& hv2, int a, int b) {
    // pow1[i] = p1^i
    ll h1 = ((hv1[b+1] - (hv1[a]*pow1[b-a+1] % mod)) % mod + mod) % mod;
    ll h2 = ((hv2[b+1] - (hv2[a]*pow2[b-a+1] % mod)) % mod + mod) % mod;
    return {h1, h2};
}