#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

const double eps = 1e-8;

bool test(int arr[3], bool used[3], int d, double acc) {
    if(abs(acc - d) < eps) {
        return true;
    }

    bool find = false;
    for(int i = 0; i < 3; ++i) {
        if(!used[i]) {
            used[i] = true;
            find |= test(arr, used, d, acc + arr[i]);
            find |= test(arr, used, d, acc - arr[i]);
            find |= test(arr, used, d, acc * arr[i]);
            find |= test(arr, used, d, acc / arr[i]);
            find |= test(arr, used, d, acc * -arr[i]);
            find |= test(arr, used, d, acc / -arr[i]);
            used[i] = false;

            if(find) {
                return true;
            }
        }
    }

    return find;
}

int main(void) {
    int d;
    cin >> d;

    if(d > 9) {
        // max (1+2)*3
        cout << "1 2 3\n";
    } else {
        // 12 74 86 
        cout << "11 23 97\n";
    }

    // int arr[3] = {1, 20, 30};
    // bool used[3] = {false, false, false};
    // bool find = false;

    // for(int i = 0; i < 3; ++i) {
    //     used[i] = true;
    //     find |= test(arr, used, d, arr[i]);
    //     // find |= test(arr, used, d, -arr[i]);
    //     used[i] = false;

    //     if(find) {
    //         break;
    //     }
    // }
    // cout << find << endl;

    // for(int a = 1; a <= 100; ++a) {
    //     if(a == d) continue;

    //     for(int b = a+1; b <= 100; ++b) {
    //         if(a == b || b == d) continue;

    //         for(int c = b+1; c <= 100; ++c) {
    //             if(b == c || a == c || c == d) continue;

    //             int arr[3] = {a, b, c};
    //             bool used[3] = {false, false, false};
    //             bool find = false;
                
    //             // cout << a << " " << b << " " << c << "\n";

    //             for(int i = 0; i < 3; ++i) {
    //                 used[i] = true;
    //                 find |= test(arr, used, d, arr[i]);
    //                 find |= test(arr, used, d, -arr[i]);
    //                 used[i] = false;

    //                 if(find) {
    //                     break;
    //                 }
    //             }

    //             if(!find) {
    //                 cout << a << " " << b << " " << c << "\n";
    //                 return 0;
    //             }
    //         }
    //     }
    // }
    return 0;
}