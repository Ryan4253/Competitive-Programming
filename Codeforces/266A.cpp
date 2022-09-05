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
	string s; cin >> s;
	int cnt = 0;
	for(int i = 1; i < n; i++){
		if(s[i] == s[i-1]){
			cnt++;
		}
	}

	cout << cnt << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
