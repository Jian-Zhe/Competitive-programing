#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

struct Record {
    int a, b, c;
    string name;
    bool operator<(const Record& r) {
        if(a == r.a && b == r.b && c == r.c) {
            return (name.compare(r.name) < 0);
        } else if(a == r.a && b == r.b) {
            return c < r.c;
        } else if(a == r.a) {
            return b < r.b;
        } else {
            return a < r.a;
        }
        return a < r.a;
    }
};

int main(void) {
    int n;
    cin >> n;
    cin.ignore();

    vector<Record> rs(n);

    string arr;
    for(int i = 0; i < n; ++i) {
        getline(cin, arr);
        stringstream ss(arr);
        ss >> rs[i].a >> rs[i].b >> rs[i].c;
        
        string str;
        while(ss >> str) {
            rs[i].name += str;
            rs[i].name += " ";
        }

        // cin.ignore();
    }

    sort(rs.begin(), rs.end());

    // for(int i = 0; i < n; ++i) {
    //     cout << rs[i].a << " " << rs[i].b << " " << rs[i].c << " " << rs[i].name << endl;
    // }

    cout << rs[n-1].name << "\n";
}