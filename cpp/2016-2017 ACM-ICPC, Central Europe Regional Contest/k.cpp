#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long int ll;

char flip(char c) {
    if(c == '0') return '1';
    else return '0';
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);

    string s;
    cin >> s;
    int n = s.size();

    int n3 = n/3;

    vector<int> mod;
    for(int i = 0; i < n; i += 3) {
        char a = s[i], b = s[i+1], c = s[i+2];
        if(a == b && b == c) {
            if(i == 0) {
                char d = s[i+3];
                if(d == c) {
                    mod.push_back(i+1);
                    s[i+2] = flip(s[i+2]);
                } else {
                    mod.push_back(i);
                }
            } else {
                char d = s[i-1];
                if(d == a) {
                    mod.push_back(i);
                } else {
                    mod.push_back(i+1);
                    s[i+2] = flip(s[i+2]);
                }
            }
        } else if(a == b && b != c) {
            mod.push_back(i+1);
            s[i+2] = flip(s[i+2]);
        } else if(a == c && a != c) {
            continue;
        } else if(b == c && a != b) {
            mod.push_back(i);
        }
    }

    cout << mod.size() << "\n";
    for(int pos : mod) {
        cout << pos+1 << " ";
    }

    return 0;
}
