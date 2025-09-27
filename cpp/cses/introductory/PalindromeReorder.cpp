#include <bits/stdc++.h>

using namespace std;

int main(void) {
    string s;
    cin >> s;

    unordered_map<char, int> cnt;
    for(char c : s) {
        cnt[c]++;
    }

    bool hasOdd = false;
    char odd;
    for(auto [ch, t] : cnt) {
        if(t % 2 == 1) {
            if(hasOdd) {
                cout << "NO SOLUTION\n";
                return 0;
            } else {
                hasOdd = true;
                odd = ch;
            }
        }
    }

    string res = "";
    if(hasOdd) {
        res.push_back(odd);
    }

    string sym = "";
    for(auto [ch, t] : cnt) {
        for(int i = 0; i < t/2; ++i) {
            sym.push_back(ch);
        }
    }

    cout << sym << res;
    reverse(sym.begin(), sym.end());
    cout << sym << "\n";
    return 0;
}