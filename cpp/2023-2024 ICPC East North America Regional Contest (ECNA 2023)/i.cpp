#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long int ll;


int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;
    cin >> n;

    regex pat("([0-9]*[0-9X])|([0-9]+-[0-9]*[0-9X])|([0-9]+-[0-9]+-[0-9]+-[0-9X])|([0-9]+-[0-9]+-[0-9]*[0-9X])");

    while(n--) {
        string str;
        cin >> str;
        if(!regex_match(str, pat)) {
            cout << "invalid\n";
            continue;
        }

        int index = 10;
        int sum = 0;
        int hyp = 0;
        for(char c : str) {
            if(c == '-') {
                hyp++;
                continue;
            } else if(c == 'X') {
                sum += index * 10;
                index--;
            } else {
                sum += index * (c-'0');
                index--;
            }
        }

        if(str.size() - hyp != 10) {
            cout << "invalid\n";
            continue;
        }

        if(sum % 11 != 0) {
            cout << "invalid\n";
            continue;
        }

        str = "978-" + str;
        str.pop_back();

        index = 0;
        sum = 0;
        for(char c : str) {
            if(c == '-') {
                continue;
            } else if(c == 'X') {
                sum += (index % 2 == 0) ? 10 : 30;
                index++;
            } else {
                sum += (index % 2 == 0) ? (c-'0') : 3*(c-'0');
                index++;
            }
        }

        sum %= 10;
        char ch = (10 - sum) % 10;
        ch += '0';
        str.push_back(ch);
        cout << str << "\n";
    }
    return 0;
}
