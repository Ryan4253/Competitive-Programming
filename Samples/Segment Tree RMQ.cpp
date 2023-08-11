#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

struct Node{
	int val;
	int l, r;
	int lson, rson;
};

const int N = 1000000 + 5;
int a[N];
Node st[2 * N];
int st_ptr = 1;

void build(int l, int r, int index){
	st[index].l = l; st[index].r = r;
	if(l + 1 == r){
		st[index].val = a[l];
		return;
	}
	int mid = (l + r) / 2;
	st[index].lson = ++st_ptr;
	st[index].rson = ++st_ptr;
	build(l, mid, st[index].lson);
	build(mid, r, st[index].rson);
	
	st[index].val = min(st[st[index].lson].val, st[st[index].rson].val);
	
}

void modify(int x, int y, int index){
	if(st[index].l +1 == st[index].r){
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

int query(int l, int r, int index){
	if(st[index].l == l && st[index].r == r){
		return st[index].val;
	}
	
	int mid = (st[index].l + st[index].r) / 2;
	if(r <= mid){
		return query(l, r, st[index].lson);
	}
	else if(l >= mid){
		return query(l, r, st[index].rson);
	}
	else{
		return min(query(l, mid, st[index].lson), query(mid, r, st[index].rson));
	}
}

void solve(){
	int m, n; cin >> m >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	build(0, n, 1);
	int r, x, y;
	
	while(m--){
		cin >> r >> x >> y;
		if(r == 2){
			modify(x, y, 1);
		}
		else{
			cout << query(x, y + 1, 1) << endl;
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

