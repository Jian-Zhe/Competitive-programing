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

    if(xvec.size() == 1) {
        cout << x_y[xvec[0]].size() + 1 + one.size() << "\n";
        if(one.size() != 0) {
            cout << xvec[0] << " 1\n";
        }

        for(ll y : x_y[xvec[0]]) {
            cout << xvec[0] << " " << y << "\n";
        }

        if(xvec[0] != 1) {
            cout << xvec[0]-1 << " 2\n";
        } else {
            cout << "2 1\n";
        }
        return 0;
    }

    for(int i = 0; i < xvec.size()-1; ++i) {
        vector<ll>& curr = x_y[xvec[i]];
        if(res.size() != 0 && (res[res.size()-1].first != xvec[i] || res[res.size()-1].second != 2)) {
            res.push_back({xvec[i], 2});
        }

        for(ll y : curr) {
            if(i == 0 || y != 2) {
                res.push_back({xvec[i], y});
            }
        }

        if(xvec[i] + 1 != xvec[xvec.size()-1]) {
            res.push_back({xvec[i] + 1, 2});
        }
    }

    // last column
    vector<ll>& curr = x_y[xvec[xvec.size()-1]];
    if(res.size() != 0 && xvec[xvec.size()-1] > res[res.size()-1].first + 1) {
        res.push_back({xvec[xvec.size()-1]-1, 2});
    }

    for(int i = curr.size()-1; i >= 0; --i) {
        res.push_back({xvec[xvec.size()-1], curr[i]});
    }

    // one
    if(one.size() == 0 || one[one.size()-1] != xvec[xvec.size()-1]) {
        res.push_back({xvec[xvec.size()-1], 1});
    }

    for(int i = one.size()-1; i >= 0; --i) {
        res.push_back({one[i], 1});
    }

    if(one.size() == 0 || one[0] != xvec[0]) {
        res.push_back({xvec[0], 1});
    }

    // check
    set<pii> rr(res.begin(), res.end());
    for(int i = 0; i < xvec.size(); ++i) {
        for(ll y : x_y[xvec[i]]) {
            assert(rr.find({xvec[i], y}) != rr.end());
        }
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