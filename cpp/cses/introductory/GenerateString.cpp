#include <bits/stdc++.h>

using namespace std;

int main(void) {

    string s;
    cin >> s;

    sort(s.begin(), s.end());

    set<string> res;
    res.insert(s);
    while(next_permutation(s.begin(), s.end())) {
        res.insert(s);
    }

    cout << res.size() << "\n";

    for(string str : res) {
        cout << str << "\n";
    }

    return 0;
}