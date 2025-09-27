#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    vector<string> res;
    res.push_back("0");
    res.push_back("1");

    for(int i = 2; i <= n; ++i) {
        
        int sz = res.size();

        for(int j = sz-1; j >= 0; --j) {
            res.push_back("1" + res[j]);
            res[j] = "0" + res[j];
        }
    }

    for(int i = 0; i < res.size(); ++i) {
        cout << res[i] << "\n";
    }

    return 0;
}