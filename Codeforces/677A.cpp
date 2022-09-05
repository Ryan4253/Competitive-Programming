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
	int n, h; cin >> n >> h;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	int sol = 0;

	for(int i = 0; i < n; i++){
		if(a[i] > h){
			sol += 2;
		}
		else{
			sol += 1;
		}
	}

	cout << sol << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
