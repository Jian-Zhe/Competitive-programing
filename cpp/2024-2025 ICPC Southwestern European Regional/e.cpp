#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

using ll = long long int;
using pii = pair<ll, ll>;

bool cmp(const pii& p1, const pii& p2) {
    return p1.first == p2.first ? p1.second < p2.second : p1.first < p2.first;
}

int main(void) {
    cin.tie(0) -> sync_with_stdio(0);
    int n;
    cin >> n;
    
    vector<pii> ps;
    ll x, y;

    set<ll> xset;
    unordered_map<ll, ll> miny, maxy;

    unordered_map<ll, vector<ll>> x_y;

    vector<ll> one;

    ll global_min_y = 2;

    for(int i = 0; i < n; ++i) {
        cin >> x >> y;
        
        if(xset.find(x) == xset.end()) {
            xset.insert(x);
            miny[x] = y;
            maxy[x] = y;
        } else {
            miny[x] = min(miny[x], y);
            maxy[x] = max(maxy[x], y);
        }
        if(y > 1) {
            x_y[x].push_back(y);
        } else {
            one.push_back(x);
        }
    }

    vector<ll> xvec(xset.begin(), xset.end());
    vector<pii> res;

    for(auto it = x_y.begin(); it != x_y.end(); it++) {
        sort(it->second.begin(), it->second.end());
    }

    sort(one.begin(), one.end());

    // res.push_back({xvec[0], 1});

    for(ll y : x_y[xvec[0]]) {
        res.push_back({xvec[0], y});
    }

    if(xvec[0] + 1 != xvec[xvec.size()-1]) {
        res.push_back({xvec[0] + 1, 2});
    }

    for(int i = 1; i < xvec.size()-1; ++i) {
        int last = res.size() - 1;
        vector<ll>& curr = x_y[xvec[i]];

        if(res[last].first != xvec[i] && curr[0] != 2) {
            res.push_back({xvec[i], 2});
        }

        for(ll y : curr) {
            res.push_back({xvec[i], y});
        }

        if(xvec[i] + 1 != xvec[xvec.size()-1]) {
            res.push_back({xvec[i]+1, 2});
        }
    }

    if(xvec.size() > 1) {
        int last = xvec.size()-1;

        if(res[res.size()-1].first < xvec[last] - 1) {
            res.push_back({xvec[last] - 1, 2});
        }

        vector<ll>& curr = x_y[xvec[last]];
        for(auto it = curr.rbegin(); it != curr.rend(); it++) {
            res.push_back({xvec[last], *it});
        }
        
        if(curr[0] != 1) {
            res.push_back({xvec[last], 1});
        }
    }

    for(int i = one.size()-1; i >= 0; --i) {
        res.push_back({one[i], 1});
    }

    if(one.size() < 1 || one[0] != xvec[0]) {
        res.push_back({xvec[0], 1});
    }

    if(res.size() > 3 * n) {
        assert(false);
    }

    if(set(res.begin(), res.end()).size() != res.size()) {
        assert(false);
    }

    cout << res.size() << "\n";
    for(const pii& p : res) {
        if(p.first < 1 || p.first > 1000000000 || p.second < 1 || p.second > 1000000000) {
            assert(false);
        }
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}