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

	int mx = a[0];
	int mn = a[0];
	int sol = 0;

	for(int i = 1; i < n; i++){
		if(mx < a[i]){
			mx = a[i];
			sol++;
		}
		if(mn > a[i]){
			mn = a[i];
			sol++;
		}
	}

	cout << sol << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
