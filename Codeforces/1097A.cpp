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
	
	for(int i = 0; i < 5; i++){
		string test; cin >> test;
		if(s[0] == test[0] || s[1] == test[1]){
			cout << "YES" << endl;
			return;
		}
	}

	cout << "NO" << endl;


}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
