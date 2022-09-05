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
	int n, k, l, c, d, p, nl, np; cin >> n >> k >> l >> c >> d >> p >> nl >> np;
	int volume = k * l;
	int lime = c * d;

	int drink = volume / nl;
	int salt = p / np;

	cout << min({drink, lime, salt}) / n << endl;


}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
