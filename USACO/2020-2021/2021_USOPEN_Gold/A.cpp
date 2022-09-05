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

const int N = 200000 + 5;
int a[N];
int fwd[N];
int back[N];

/*
int mxi[N];
Node st[2*N];
int st_ptr = 1;

void build(int l, int r, int index){
	st[index].l = l, st[index].r = r;
	if(l + 1 == r){
		st[index].val = mxi[l];
		return;
	}

	st[index].lson = ++st_ptr;
	st[index].rson = ++st_ptr;

	int mid = (st[index].l + st[index].r) / 2;
	build(st[index].l, mid, st[index].lson);
	build(mid, st[index].r, st[index].rson);

	st[index].val = min((st[index].l).val, (st[index].r).val);
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
		return min(query(l, mid, st[index].lson), query(mid, r, st[index].rson));
	}
}
*/

bool ok(int i, int j){
	if(back[j] < i && fwd[i] > j){
		return true;
	}
	else{
		return false;
	}
}

void solve(){
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	bool found;
	for(int i = 0; i < n; i++){
		found = false;
		for(int j = i+1; j < n; j++){
			if(a[i] == a[j]){
				fwd[i] = j;
				found = true;
				break;
			}
		}

		if(!found){
			fwd[i] = 100000000;
		}
	}
	/*
	cout << "FWD ";
	for(int i = 0; i < n; i++){
		cout << fwd[i] << " ";
	}
	cout << endl;
	*/
	for(int i = 0; i < n; i++){
		found = false;
		for(int j = i-1; j >= 0; j--){
			if(a[i] == a[j]){
				back[i] = j;
				found = true;
				break;
			}
		}

		if(!found){
			back[i] = -100000000;
		}
	}
	/*
	cout << "BACK ";
	for(int i = 0; i < n; i++){
		cout << back[i] << " ";
	}
	cout << endl;
	*/
	int sol = 0;
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			if(ok(i, j)){
				sol++;
			}
		}
	}

	cout << sol << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
