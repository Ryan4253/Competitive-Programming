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
	int n, m; cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			string s; cin >> s;
			if(s != "W" && s != "B" && s != "G"){
				cout << "#Color" << endl;
				return;
			}
		}
	}

	cout << "#Black&White" << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
