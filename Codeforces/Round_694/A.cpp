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
	int n, x; cin >> n >> x;
	int a[n];

	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	ll int sum = 0;
	ll int total = 0;
	for(int i = 0; i < n; i++){
		total += a[i];
		sum += a[i]/x;
		a[i] %= x;
	}

	ll int modsum = 0;
	ll int modcnt = 0;
	for(int i = 0; i < n; i++){
		modsum += a[i];
		modcnt += (a[i] != 0);
	}
	/*
	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	cout << endl;
	*/
	if(total % x == 0){
		cout << total/x<< " " << sum + modcnt << endl;
	}
	else{
		cout << total/x+1 << " " << sum + modcnt << endl;
	}

	//cout << minbt << " " << maxbt << endl;
	/*
	for(int i = 0; i < v.size(); i++){
		cout << v[i] << endl;
	}
	*/
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--){
		solve();
 	}
}
