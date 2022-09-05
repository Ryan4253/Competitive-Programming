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
	int n, k; cin >> n >> k;
	int a[n], b[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i++){
		cin >> b[i];
	}

	sort(a, a + n);
	sort(b, b + n, greater<int>());

	int cnt = 0;
	int sol = 0;
	for(int i = 0; i < n; i++){
		if(b[i] > a[i] && cnt < k){
			sol += b[i];
			cnt++;
		}
		else{
			sol += a[i];
		}
	}

	cout << sol << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--){
		solve();
	}
}
