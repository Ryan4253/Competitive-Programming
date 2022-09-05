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
	reverse(s.begin(), s.end());

	for(int i = 0; i < n; i++){
		if(s[i] != ')'){
			if(i > n-i){
				cout << "YES" << endl;
			}
			else{
				cout << "NO" << endl;
			}
			return;
		}

	}

	cout << "YES" << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--){
		solve();
 	}
}
