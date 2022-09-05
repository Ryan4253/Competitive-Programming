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
	string s; cin >> s;
	string sol = "";
	sol += s[0];
	for(int i = 1; i < s.length()-1; i+= 2){
		sol += s[i];
	}

	sol += s.back();

	cout << sol << endl;

}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--){
		solve();
 	}
}
