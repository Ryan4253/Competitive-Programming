#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second


void solve(){
	int k, l, m, n, d; cin >> k >> l >> m >> n >> d;
	int a[d];
	for(int i = 0; i <= d; i++){
		a[i] = 1;
	}

	for(int i = k; i <= d; i += k){
		a[i] = 0;
	}
	for(int i = l; i <= d; i += l){
		a[i] = 0;
	}
	for(int i = m; i <= d; i += m){
		a[i] = 0;
	}
	for(int i = n; i <= d; i += n){
		a[i] = 0;
	}

	int sol = 0;

	for(int i = 1; i <= d; i++){
		sol += a[i];
	}

	cout << d - sol << endl;

}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
