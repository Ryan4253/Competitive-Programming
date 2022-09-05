#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

//void clear(int n){for(int i = 0; i < n; i++){a[i] = 0;}}

const int N = 100000 + 10;
int a[N];
int root[N];

struct Node{
    int val;
    int l, r;
    int lson, rson;
};Node st[20*N];

int st_ptr = 0;

void pull(int index){
    (st[index].val) = st[(st[index].lson)].val + st[(st[index].rson)].val;
}

int gNode(int oldNode){
    int newNode = ++st_ptr;
    st[newNode] = st[oldNode];
    return newNode;
}

void build(int l, int r, int index){
     st[index].l = l, st[index].r = r;
     if(l + 1 == r){
         st[index].val = 0;
         return;
     }
     
     int mid = (l + r) / 2;
     st[index].lson = ++st_ptr;
     st[index].rson = ++st_ptr;
     
     build(l, mid, st[index].lson);
     build(mid, r, st[index].rson);
}

void modify(int oldNode, int newNode, int l, int r, int pos){
    if(l + 1 == r){
        st[newNode].val++;
        return;
    }
    
    int mid = (l + r) / 2;
    
    if(pos < mid){
        st[newNode].lson = gNode(st[oldNode].lson);
        modify(st[oldNode].lson, st[newNode].lson, l, mid, pos);
    }
    else{
        st[newNode].rson = gNode(st[oldNode].rson);
        modify(st[oldNode].rson, st[newNode].rson, mid, r, pos);
    }
    pull(newNode);
}

int query(int l, int r, int index){
    if(st[index].l == l && st[index].r == r){
        return st[index].val;
    }
    
    int mid = (st[index].l + st[index].r) / 2;
    if(mid <= l){
        return query(l, r, st[index].rson);
    }
    else if(mid >= r){
        return query(l, r, st[index].lson);
    }
    else{
        return query(l, mid, st[index].lson) + query(mid, r, st[index].rson);
    }
}

void solve(){
	int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    root[0] = ++st_ptr;
    build(1, n+1, root[0]);
    for (int i = 1; i <= n; ++i) {
        root[i] = gNode(root[i - 1]);
        modify(root[i - 1], root[i], 1, n+1, a[i - 1]);
    }

    
    for(int i = 0; i < m; i++){
        int l, r, aa, b; cin >> l >> r >> aa >> b;
        cout << query(aa, b+1, root[r]) - query(aa, b+1, root[l - 1]) << endl;
    }
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}