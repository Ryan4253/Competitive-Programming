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
	int n; cin >> n;
	int a[n];

	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	int mx = 0;
	int mn = 0;

	for(int i = 1; i < n; i++){
		if(a[mx] < a[i]){
			mx = i;
		}

		if(a[mn] >= a[i]){
			mn = i;
		}
	}

	if(mx > mn){
		cout << (mx) + n - mn -2 << endl; 
	}
	else{
		cout << (mx + n - mn-1) << endl;
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
	