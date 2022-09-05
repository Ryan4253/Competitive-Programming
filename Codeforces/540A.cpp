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
	string a, b; cin >> a >> b;
	int sol = 0;
	for(int i = 0; i < n; i++){
		int dist = max(a[i], b[i]) - min(a[i], b[i]);
		sol += min(dist, 10 - dist);
	}

	cout << sol << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
