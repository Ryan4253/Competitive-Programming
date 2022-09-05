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

	int sol = 0;

	int ava = 0;
	for(int i = 0; i < n; i++){
		ava += a[i];
		if(ava < 0){
			sol += -ava;
			ava = 0;
		}
	}

	cout << sol << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
