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
	int k, n, w; cin >> k >> n >> w;
	int cost = k * (w * (w+1)) / 2;

	cout << max(0, cost - n) << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
