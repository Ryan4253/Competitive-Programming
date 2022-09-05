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
	int a[4];
	for(int i = 0; i < 4; i++){
		cin >> a[i];
	}

	string s; cin >> s;
	int sol = 0;
	for(int i = 0; i < s.size(); i++){
		sol += a[s[i]-49];
	}

	cout << sol << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
