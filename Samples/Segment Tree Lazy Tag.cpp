#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define F first;
#define S second;

struct Node{
    int val; // max value
    int l, r;
    int lson, rson;
    int tag;
};

const int N = 100000 + 5;
Node st[2 * N];
int a[N];
int st_ptr = 0;

void build(int l, int r, int index){
    st[index].l = l, st[index].r = r;
    st[index].tag = 0;
    if(l + 1 == r){
        st[index].val = a[l];
        return;
    }
    
    int mid = (l + r) / 2;
    st[index].lson = ++st_ptr;
    st[index].rson = ++st_ptr;
    
    build(l, mid, st[index].lson);
    build(mid, r, st[index].rson);
    
    st[index].val = max(st[st[index].lson].val, st[st[index].rson].val);
}

void push(int index){
    st[index].val += st[index].tag;    
    if(st[index].l + 1 != st[index].r){
        st[st[index].lson].tag += st[index].tag;
        st[st[index].rson].tag += st[index].tag;
    }
    st[index].tag = 0;
}

int query(int l, int r, int index){
    push(index);
    if (st[index].l == l && st[index].r == r) {
        return st[index].val;
    }


    
    int mid = (st[index].l + st[index].r) / 2;
    
    if(l >= mid){
        return query(l, r, st[index].rson);
    }
    else if(mid >= r){
        return query(l, r, st[index].lson);
    }
    else{

        return max(query(l, mid, st[index].lson), query(mid, r, st[index].rson));
    }
}

void modify(int l, int r, int dVal, int index){
    push(index);
    if(st[index].l == l && st[index].r == r){
        st[index].tag += dVal;
        return;
    }
    
    int mid = (st[index].l + st[index].r) / 2;
    
    if(l >= mid){
        modify(l, r, dVal, st[index].rson);
    }
    else if(r <= mid){
        modify(l, r, dVal, st[index].lson);
    }
    else{
        modify(l, mid, dVal, st[index].lson);
        modify(mid, r, dVal, st[index].rson);
    }
    
    st[index].val = max(st[st[index].lson].val + st[st[index].lson].tag, st[st[index].rson].val +     st[st[index].rson].tag);
}

void solve(){
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    
    build(1, n+1, 0);

    
    for(int i = 0; i < q; i++){
        int t, l, r; cin >> t >> l >> r;
        if(t == 1){
            int x; cin >> x;
            modify(l, r+1, x ,0);
        }
        else{
            cout << query(l, r+1, 0) << endl;
        }
    }
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n = 1;
  while(n--){
    solve();
  }
}




