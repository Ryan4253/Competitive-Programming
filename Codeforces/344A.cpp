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
	vector<int> v;
	for(int i = 0; i < n; i++){
		string s; cin >> s;
		if(s == "01"){
			v.pb(1);
		}
		else{
			v.pb(0);
		}
	}

	int sol = 1;
	for(int i = 1; i < n; i++){
		if(v[i] != v[i-1]){
			sol++;
		}
	}

	cout << sol << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
