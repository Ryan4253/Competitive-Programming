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
	string s, t; cin >> s >> t;
	string sol = "";
	for(int i = 0; i < s.size(); i++){
		if(s[i] == t[i]){
			sol += '0';
		}
		else{
			sol += '1';
		}
	}

	cout << sol << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
