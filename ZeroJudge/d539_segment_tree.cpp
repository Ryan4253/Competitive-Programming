#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

const int N = 500000 + 5;
int a[N];


struct Node{
    int val;
    int l, r;
    int lson, rson;
};

Node st[2 * N];
int st_ptr = 0;

int ask(int l, int r, int index){
    if(st[index].l == l && st[index].r == r){
        return st[index].val;
    }
    
    int mid = (st[index].l + st[index].r) / 2;
    
    if(l >= mid){
        return ask(l, r, st[index].rson);
    }
    else if(r <= mid){
        return ask(l, r, st[index].lson);
    }
    else{
        return max(ask(l, mid, st[index].lson), ask(mid, r, st[index].rson));
    }
}

void build(int l, int r, int index){
    st[index].l = l; st[index].r = r;
    if(l + 1 == r){
        st[index].val = a[l];
        return;
    }
    
    int mid = (st[index].l + st[index].r) / 2;
    st[index].lson = (++st_ptr);
    st[index].rson = (++st_ptr);
    build(l, mid, st[index].lson);
    build(mid, r, st[index].rson);
    
    st[index].val = max(st[st[index].lson].val, st[st[index].rson].val);
}

void solve(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    build(1, n+1, st_ptr);
    
    int x; cin >> x;
    int a, b;
    for(int i = 0; i < x; i++){
        cin >> a >> b;
        if(a > b){
            cout << ask(b, a+1, 1) << endl;
        }
        else{
            cout << ask(a, b+1, 1) << endl;
        }
    }
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
    solve();
}


