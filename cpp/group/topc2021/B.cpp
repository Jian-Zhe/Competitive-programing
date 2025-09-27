#include <bits/stdc++.h>

using namespace std;

using ll = long long int;

int main(void) {
    int n;
    cin >> n;

    while(n--) {
        int val;
        cin >> val;

        int sq = sqrt(val);
        int end = sq;

        ll sum = 1;
        if(val == 1) {
            sum = 0;
        }

        for(int i = 2; i <= end; ++i) {
            if(val % i == 0) {
                if(i != val / i) {
                    sum += i;
                    sum += val / i;
                } else {
                    sum += i;
                }

                if(sum > val) {
                    break;
                }
            }
        }

        if(sum > val) {
            cout << "abundant\n";
        } else if(sum == val) {
            cout << "perfect\n";
        } else {
            cout << "deficient\n";
        }
    }
}