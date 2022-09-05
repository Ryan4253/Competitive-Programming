#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

const int N = 10000 + 5;
ll int a[N];
ll int b[N];
ll int c[N];
ll int v[N];

bool check(ll int m, ll int n, ll int k){
	ll int win = 0;
	for(int i = 0; i < n; i++){
		v[i] = (a[i] + b[i] * m);
	}

	sort(v, v + n, greater<ll int>());

	for(int i = 0; i < k; i++){
		if(v[i] > c[i]){
			win++;
		} 
	}

	return win == k;
}

void solve(){
	ll int n, k; cin >> n >> k;

	for(int i = 0; i < n; i++){
		cin >> a[i] >> b[i];
	}

	for(int i = 0; i < n; i++){
		cin >> c[i];
	}

	sort(c, c + n);
	reverse(c, c + k);

	ll int l = -1;
	ll int r = 100000005;
	bool flag = false;

	while(l + 1 != r){
		ll int mid = (l + r) / 2;

		if(check(mid, n, k)){
			r = mid;
			flag = true;
		}
		else{
			l = mid;
		}
	}
	
	cout << (flag ? to_string(r) : "-1") << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--){
		solve();
 	}
}