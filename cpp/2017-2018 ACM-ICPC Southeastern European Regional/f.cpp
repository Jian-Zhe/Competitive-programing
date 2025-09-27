#include <bits/stdc++.h>

using namespace std;

using ll = long long int;

vector<ll> cost;

bool cmp(int a, int b) {
    return cost[a] < cost[b];
}

int main(void) {
    int n;
    cin >> n;

    cost = vector<ll>(n);

    for(int i = 0; i < n; ++i) {
        cin >> cost[i];
    }

    string a, b;
    cin >> a >> b;

    vector<int> to1;
    vector<int> to0;

    vector<int> one;

    ll raw;
    ll total = 0;
    for(int i = 0; i < n; ++i) {
        if(a[i] == '1') {
            total += cost[i];

            if(b[i] == '1') {
                one.push_back(i);
            }
        }

        if(a[i] != b[i]) {
            if(a[i] == '1') {
                to0.push_back(i);
            } else {
                to1.push_back(i);
            }
        }
    }

    sort(one.begin(), one.end(), cmp);
    sort(to0.begin(), to0.end(), cmp);
    sort(to1.begin(), to1.end(), cmp);

    ll res = LLONG_MAX;

    vector<int> arr = to0;
    vector<int> brr = to1;

    for(int from = one.size(); from >= 0; --from) {
        ll res2 = 0;
        ll sum = total;
        
        if(from >= 0 && from < one.size()) {
            arr.insert(lower_bound(arr.begin(), arr.end(), one[from], cmp), one[from]);
            brr.insert(lower_bound(brr.begin(), brr.end(), one[from], cmp), one[from]);
        }

        for(int i = arr.size()-1; i >= 0; --i) {
            sum -= cost[arr[i]];
            res2 += sum;
        }

        for(int i = 0; i < brr.size(); ++i) {
            sum += cost[brr[i]];
            res2 += sum;
        }

        res = min(res, res2);
    }

    cout << res << "\n";

    return 0;
}