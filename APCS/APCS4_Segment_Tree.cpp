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
	int l, r;
	int lson, rson;
};

const int N = 100000 + 5;
int a[2 * N];
Node st[2 * N];
int sol[N];
int st_ptr = 0;
bool visit[N];

void build(int l, int r, int index){
	st[index].l = l; st[index].r = r;

	if(l + 1 == r){
		st[index].val = 0;
		return;
	}

	st[index].lson = ++st_ptr;
	st[index].rson = ++st_ptr;

	int mid = (l + r) / 2;
	build(l, mid, st[index].lson);
	build(mid, r, st[index].rson);

	st[index].val = st[st[index].lson].val + st[st[index].rson].val;
}

void increment(int x, int index){
	if(st[index].l + 1 == st[index].r){
		st[index].val++;
		return;
	}

	int mid = (st[index].l + st[index].r) / 2;

	if(x <= mid){
		increment(x, st[index].lson);
	}
	else{
		increment(x, st[index].rson);
	}

	st[index].val = st[st[index].lson].val + st[st[index].rson].val;
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
		return query(l, mid, st[index].lson) + query(mid, r, st[index].rson);
	}
}

void solve(){
	int n; cin >> n;
	for(int i = 0; i < 2 * n; i++){
		cin >> a[i];
	}

	build(0, n + 1, 0);

	
	
	for(int i = 0; i < 2 * n; i++){
		int x = a[i];
		if(!visit[x]){
			sol[x] -= query(0, x, 0); 
		}
		else{
			sol[x] += query(0, x, 0)-1;
		}

		increment(x, 0);
		
		visit[x] = true;
	}
	

	ll int solution = 0;
	for(int i = 1; i <= n; i++){
		cout << sol[i] << " ";
		solution += sol[i];
	}
	cout << endl;

	cout << solution << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
