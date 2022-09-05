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
	string a, b, c; cin >> a >> b >> c;
	a += b;
	sort(a.begin(), a.end());
	sort(c.begin(), c.end());

	cout << ((a == c) ? "YES" : "NO") << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
