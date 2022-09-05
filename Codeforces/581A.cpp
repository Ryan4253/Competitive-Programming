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
	int a, b; cin >> a >> b;
	cout << min(a, b) << " " << (a + b) / 2 - min(a, b) << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
	