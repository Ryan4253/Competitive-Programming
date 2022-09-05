#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

int a[4];

void solve(){
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		a[x-1]++;
	}
	int sol = 0;

	// add 4
	sol += a[3];
	a[3] = 0;

	// group 1, 3
	if(a[2] > a[0]){
		sol += a[0];
		a[2] -= a[0];
		a[0] = 0;
	}
	else{
		sol += a[2];
		a[0] -= a[2];
		a[2] = 0;
	}

	sol += a[2];
	a[2] = 0;

	sol += a[1]/2;
	a[1] %= 2;

	sol += a[0]/4;
	a[0] %= 4;

	if(a[1] == 1){
		sol++;
		a[0] -= min(a[0], 2);
	}

	if(a[0] > 0){
		sol++;
	}

	cout << sol << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
