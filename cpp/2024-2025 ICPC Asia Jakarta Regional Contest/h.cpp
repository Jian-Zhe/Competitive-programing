#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long int ll;

const int maxn = 5001;
// sa[i]: 第i大的後綴是在哪一個index開頭的 rk[i]: 字串中第i個字母是第幾大 （數字越大越大）
int sa[maxn], rk[maxn << 1], oldrk[maxn << 1], id[maxn], cnt[maxn];

void build_sa(string str) {
    int n = str.size() - 1;
    int m = max(n, 300);
    memset(cnt, 0, sizeof(cnt));
    memset(rk, 0, sizeof(rk));

    for (int i = 1; i <= n; i++) ++cnt[rk[i] = (int)str[i]];
    for (int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
    for (int i = n; i >= 1; i--) sa[cnt[rk[i]]--] = i;

    for (int w = 1; w < n; w <<= 1) {
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; i++) id[i] = sa[i];
        for (int i = 1; i <= n; i++) ++cnt[rk[id[i] + w]];
        for (int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
        for (int i = n; i >= 1; i--) sa[cnt[rk[id[i] + w]]--] = id[i];

        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; i++) id[i] = sa[i];
        for (int i = 1; i <= n; i++) ++cnt[rk[id[i]]];
        for (int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
        for (int i = n; i >= 1; i--) sa[cnt[rk[id[i]]]--] = id[i];

        memcpy(oldrk, rk, sizeof(rk));
        for (int p = 0, i = 1; i <= n; i++) {
            if (oldrk[sa[i]] == oldrk[sa[i - 1]] &&
                oldrk[sa[i] + w] == oldrk[sa[i - 1] + w])
                rk[sa[i]] = p;
            else
                rk[sa[i]] = ++p;
        }
    }
}

class Trie {
    struct Node {
        vector<Node*> child;
        bool isEndOfWord;
        Node() {
            child = vector<Node*>(26, nullptr);
            isEndOfWord = false;
        }
        ~Node() {
            for(Node* n : child) {
                if(n) {
                    delete n;
                }
            }
        }
    };
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    void insert(string word) {
        Node* curr = root;
        for(char c : word) {
            if(!curr->child[c - 'a']) {
                curr->child[c - 'a'] = new Node();
            }
            curr = curr->child[c - 'a'];
        }
        curr->isEndOfWord = true;
    }
    bool search(string word) {
        Node* curr = root;
        for(char c : word) {
            if(!curr->child[c - 'a']) {
                return false;
            }
            curr = curr->child[c - 'a'];
        }
        return curr->isEndOfWord;
    }
};

int main(){

    string str;
    cin >> str;

    int n = str.size();

    build_sa(str);

    Trie trie;

    int start = rk[0];
    int head = 0;

    vector<string> res;
    for(int i = start+1; i < n; ++i) {
        string sub = str.substr(head, sa[i]-head);
        if(sa[i] > head && !trie.search(sub)) {
            head = sa[i];
            trie.insert(sub);

            res.push_back(sub);
        }
    }

    cout << res.size() << "\n";
    for(string s : res) {
        cout << s << "\n";
    }

    return 0;
}
