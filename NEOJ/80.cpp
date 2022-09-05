#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

const int N = 1000000 + 5;
int a[N];

struct Node{
    int val;
    int l, r; // your left / right limit
    int lson, rson;
};

Node st[2 * N];
int st_ptr = 1;

void build(int l, int r, int index){
    st[index].l = l; st[index].r = r;
    if(l + 1 == r){
        st[index].val = a[l]; 
        return;
    }
    int mid = (l + r)/2;
    st[index].lson = (++st_ptr);
    st[index].rson = (++st_ptr);
    build(l, mid, st[index].lson);
    build(mid, r, st[index].rson);
    
    st[index].val = min(st[st[index].lson].val, st[st[index].rson].val);
}

int ask(int l, int r, int index){
    if(st[index].l == l && st[index].r == r){
        return st[index].val;
    }
    
    int mid = (st[index].l + st[index].r) / 2;
    if(mid >= r){
        return ask(l, r, st[index].lson);
    }
    else if(mid <= l){
        return ask(l, r, st[index].rson);
    }
    else{
        return min(ask(l, mid, st[index].lson), ask(mid, r, st[index].rson));
    }
}

void modify(int x, int y, int index){
    if(st[index].l + 1 == st[index].r){
        st[index].val = y;
        return;
    }
    int mid = (st[index].l + st[index].r) / 2;
    if(mid > x){
        modify(x, y, st[index].lson);
    }
    else{
        modify(x, y, st[index].rson);
    }
    st[index].val = min(st[st[index].lson].val, st[st[index].rson].val);
}

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a[i];
    }
    build(0, m, st_ptr);
    int x, y, z;
    while(n--){
        cin >> x >> y >> z;
        if(x == 1){
            cout << ask(y, z+1, 1) << endl;
        }
        else{
            modify(y, z, 1);
        }
    }
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
    solve();
}
