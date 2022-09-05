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
	vector<int> v[3];

	int n; cin >> n;
	for(int i = 1; i <=n; i++){
		int x; cin >> x;
		v[x-1].pb(i);
	}

	int team = min({v[1].size(), v[0].size(), v[2].size()});
	cout << team << endl;
	for(int i = 0; i < team; i++){
		cout << v[0][i] << " " << v[1][i] << " " << v[2][i] << endl;
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
