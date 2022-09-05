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
	int n, m, k; cin >> n >> m >> k;
	string s[2] = {"No", "Yes"};

	cout << s[(n <= m && n <= k)] << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
