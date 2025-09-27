#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    vector<int> arr(n);
    vector<int> brr(n);

    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
        arr[i] -= 1;
    }

    for(int i = 0; i < n; ++i) {
        cin >> brr[i];
        brr[i] -= 1;
    }

    int res = 0;
    for(int i = 0; i < n; ++i) {
        if(arr[i] != brr[i]) {
            int pa = arr[i];
            int nxt;
            arr[i] = -1;
            while(pa != -1) {
                nxt = arr[pa];
                arr[pa] = -1;
                pa = nxt;
                res++;
            }

            if(brr[i] != -1 && arr[brr[i]] != -1) {
                int pa = arr[brr[i]];
                int nxt;
                arr[brr[i]] = -1;
                while(pa != -1) {
                    nxt = arr[pa];
                    arr[pa] = -1;
                    pa = nxt;
                    res++;
                }
            }
        }
    }

    for(int i = 0; i < n; ++i) {
        if(arr[i] != brr[i]) {
            res++;
        }
    }

    cout << res << "\n";
    return 0;
}