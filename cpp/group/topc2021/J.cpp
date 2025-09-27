#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

int main(void) {
    string a, b;
    cin >> a >> b;

    bool nan = false;
    for(char ch : a) {
        if(ch > '9' || ch < '0') {
            nan = true;
            break;
        }
    }

    for(char ch : b) {
        if(ch > '9' || ch < '0') {
            nan = true;
            break;
        }
    }

    if(nan) {
        cout << "NaN\n";
    } else {
        cout << stoll(a, 0, 10) - stoll(b, 0, 10) << "\n";
    }
    return 0;
}