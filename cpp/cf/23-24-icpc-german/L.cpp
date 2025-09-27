#include <bits/stdc++.h>

using namespace std;

using ll = long long int;

int main(void) {
    string str;
    cin >> str;

    vector<string> seg;

    int i = 0;
    int up = 0;
    int from, end;
    while(i < str.size()) {
        from = i;
        i++;
        up++;

        while(up != 0 && i < str.size()) {
            if(str[i] == '(') {
                up++;
            } else {
                up--;
            }
            ++i;
        }
        end = i;
        seg.push_back(str.substr(from, end - from));
    }

    int si = seg.size();
    string res = "";
    for(int i = 0; i < si; ++i) {
        if(seg[i] == seg[(i+1) % si]) {
            res = "";
            for(int j = 0; j < si; ++j) {
                res += seg[(i+j) % si];
            }
            if(res != str) {
                cout << res << "\n";
                return 0;
            }
        }
    }

    cout << "no\n";
    return 0;
}