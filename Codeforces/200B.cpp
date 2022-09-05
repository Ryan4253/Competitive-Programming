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
	double sol = 0;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		sol += x;
	}

	cout << sol / n << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
