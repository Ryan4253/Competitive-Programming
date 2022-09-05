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
	int val;
	int lson, rson;
	int l, r;
};

const int N = 1000000 + 5;
int a[N];
Node st[2 * N];
int st_ptr = 0;
int cnt[N];
vector<int> v;

void discretization(int n){
	for(int i = 0; i < n ; i++){
		v.pb(a[i]);
	}
	
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	
	for(int i = 0; i < n; i++){
		a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
	}
}

void build(int l, int r, int index){
	st[index].l = l; st[index].r = r;
	if(l + 1 == r){
		st[index].val = 0;
		return;
	}
	
	st[index].lson = ++st_ptr;
	st[index].rson = ++st_ptr;
	int mid = (st[index].l + st[index].r) / 2;
	
	build(l, mid, st[index].lson);
	build(mid, r, st[index].rson);
	
	st[index].val = st[st[index].lson].val + st[st[index].rson].val;
}

int query(int l, int r, int index){
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

void increment(int x, int index){
	if(st[index].l + 1 == st[index].r){
		st[index].val++;
		return;
	}
	
	int mid = (st[index].l + st[index].r) / 2;
	
	if(x >= mid){
		increment(x, st[index].rson);
	}
	else{
		increment(x, st[index].lson);
	}
	
	st[index].val = st[st[index].lson].val + st[st[index].rson].val;
}

void solve(){
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	build(0, n, 0);
	discretization(n);
	
	int invpair = 0;
	
	for(int i = 0; i < n; i++){
		
		invpair += query(a[i], n, 0) - cnt[a[i]];
		cnt[a[i]]++;
		increment(a[i], 0);
	//	cout << invpair << endl;
	}
	
	if((3 * n - invpair) % 2 == 0){
		cout << "Petr" << endl;
	}
	else{
		cout << "Um_nik" << endl;
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n = 1;
	while(n--){
		solve();
 	}
}

