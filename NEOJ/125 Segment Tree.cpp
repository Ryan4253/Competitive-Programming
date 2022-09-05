#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

struct Node{
    pii val;
    int l, r;
    int lson, rson;
};

const int N = 1000000 + 5;
const int X = 10000019;
int st_ptr = 0;
int a[N];
int dis[N];
vector<int> v;
Node st[N];
Node st2[N];

/*
pair<int, int> operator+(const pair<int, int> &p1, const pair<int, int> &p2) {
    return make_pair(p1.first + p2.first, p1.second + p2.second);
}
*/

pii operator+(const pii &p1, const pii &p2){
    return mp((p1.F + p2.F) % X, (p1.S + p2.S) % X);
}

void discretization(int n){
    for(int i = 0; i < n; ++i){
        v.pb(a[i]);
    }
    
    sort(v.begin(), v.end());
    
    v.resize(unique(v.begin(), v.end()) - v.begin());
    
    for(int i = 0; i < n; i++){
        dis[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
    }
}

void build(int l, int r, int index){
    st[index].l = l; st[index].r = r;
    if(l + 1 == r){
        st[index].val = mp(0, 0);
        return;
    }
    
    st[index].lson = ++st_ptr;
    st[index].rson = ++st_ptr;
    int mid = (st[index].l + st[index].r) / 2;
    
    build(l, mid, st[index].lson);
    build(mid, r, st[index].rson);
    
    st[index].val = mp(0, 0);
}

void modify(int x, int value, int index){
    if(st[index].l + 1 == st[index].r){
        (st[index].val).F++;
        ((st[index].val).S += value) % X;
        return;
    }
    
    int mid = (st[index].l + st[index].r) / 2;
    if(x >= mid){
        modify(x, value, st[index].rson);
    }
    else{
        modify(x, value, st[index].lson);
    }
    
    st[index].val = (st[st[index].lson].val + st[st[index].rson].val);
}

pii query(int l, int r, int index){
    if(st[index].l == l && st[index].r == r){
        return st[index].val;
    }
    
    int mid = (st[index].l + st[index].r) / 2;
    
    if(l >= mid){
        return query(l, r, st[index].rson);
    }
    else if(r <= mid){
        return query(l, r, st[index].lson);
    }
    else{
        return query(l, mid, st[index].lson) + query(mid, r, st[index].rson);
    }
}

int rit() {
    int ret = 0;
    char c;
    do {
        c = getchar_unlocked();
    } while (c < '0' || c > '9');
    do {
        ret = (ret << 1) + (ret << 3) + (c - '0');
        c = getchar_unlocked();
    } while ('0' <= c && c <= '9');
    return ret;
}

void solve(){
    int n = rit();
    for(int i = 0; i < n; ++i){
        a[i] = rit();
    }   
    discretization(n);
    
    build(0, n, 0);
    
    ll int sol = 0;
    int invpair = 0;
    
    pii temp;
    for(int i = 0; i < n; ++i){
        if(dis[i] == n-1){
            ;
        }
        else{
            temp = query(dis[i] + 1, n, 0); 
            sol += (1ll * temp.F * a[i] + 1ll * temp.S) % X;
        } 
        modify(dis[i], a[i], 0);
    }
    
    cout << sol % X << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n = 1;
	while(n--){
		solve();
 	}
}
