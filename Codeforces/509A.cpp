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
	int a[n][n];

	for(int i = 0; i < n; i++){
		a[0][i] = 1;
		a[i][0] = 1;
	}

	for(int i = 1; i < n; i++){
		for(int j = 1; j < n; j++){
			a[i][j] = a[i-1][j] + a[i][j-1];
		}
	}

	cout << a[n-1][n-1] << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
