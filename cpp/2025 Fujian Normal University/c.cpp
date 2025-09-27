#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long int ll;

struct node {
    vector<int> from;
    vector<int> to;
};

node mn[200005];

void pull(const node& l_child, const node& r_child, node& me, int remove, int add) {
    me.from.clear();
    me.to.clear();

    const vector<int>& l_from = l_child.from;
    const vector<int>& l_to = l_child.to;
    const vector<int>& r_from = r_child.from;
    const vector<int>& r_to = r_child.to;

    int i = 0, j = 0;
    int ni = l_from.size();
    int nj = r_from.size();

    while(i < ni && j < nj) {
        if(l_from[i] < r_from[j]) {
            if(remove > l_from[i] && remove < l_to[i]) {
                me.from.push_back(l_from[i]);
                me.from.push_back(remove+1);
                me.to.push_back(remove-1);
                me.to.push_back(l_to[i]);
                i++;
            } else if(remove == l_from[i]) {
                
            }
        }
    }

} 

void update(int x, int l, int r, int pos, const int& remove, const int& add){
    if(l == r){
        // TODO:: update leaf
        return;
    }
    int mid = (l+r)/2;
    if(pos <= mid) update(x*2,l,mid,pos, remove, add);
    else update(x*2+1,mid+1,r,pos, remove, add);

    pull(mn[x*2], mn[x*2+1], mn[x], remove, add);
}

int query(int x,int l,int r,int ql,int qr){
    if(ql<=l && r<=qr) return mn[x];
    int mid = (l+r)/2;
    int ret = 1e9;
    if(ql <= mid) ret = min(ret,query(x*2,l,mid,ql,qr));
    if(mid < qr) ret = min(ret,query(x*2+1,mid+1,r,ql,qr));
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
