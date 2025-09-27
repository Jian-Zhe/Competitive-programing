#include <bits/stdc++.h>

using namespace std;

void hanoi(int n, int a, int b, int c) {
    if(n == 1) {
        cout << a << " " << c << "\n";
        return;
    }

    hanoi(n-1, a, c, b);
    cout << a << " " << c << "\n";
    hanoi(n-1, b, a, c);
}

int main(void) {
    int n;
    cin >> n;

    int t = 1;
    for(int i = 1; i <= n; ++i) {
        t *= 2;
    }

    cout << t-1 << "\n";

    hanoi(n, 1, 2, 3);
    return 0;
}