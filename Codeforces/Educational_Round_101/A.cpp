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
	if(s[0] == ')' || s[s.size()-1] == '(' || s.size() % 2 == 1){
		cout << "NO" << endl;
	}
	else{
		cout << "YES" << endl;
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--){
		solve();
 	}
}


