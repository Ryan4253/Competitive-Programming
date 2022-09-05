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
	int x, y; cin >> x >> y; // x == jc, y == cj
	string s; cin >> s;

	vector<char> v;
	v.pb(s[0]);
	for(int i = 1; i < s.size(); i++){
		if(s[i] != s[i-1]){
			v.pb(s[i]);
		}
	}

	if(v.size() == 0){
		cout << 0 << endl;
		return;
	}

	for(int i = 0; i < v.size(); i++){
		if(v[i] == '?'){
			if(i == 0){
				v[i] = v[i+1];
			}
			else if(i == v.size()-1){
				v[i] = v[i-1];
			}
			else if(v[i+1] == v[i-1]){
				v[i] = v[i+1];
			}
			else if(v[i-1] == 'C' && v[i+1] == 'J'){
				v[i] = (x >= y) ? 'J' : 'C';
			}
			else{
				v[i] = (x >= y) ? 'C' : 'J';
			}
		}
	}

	/*
	for(int i = 0; i < v.size(); i++){
		cout << v[i];
	}
	cout << endl;
	*/

	int sol = 0;
	for(int i = 0; i < v.size()-1; i++){
		if(v[i] == 'C' && v[i+1] == 'J'){
			sol += x;
		}
		else if(v[i] == 'J' && v[i+1] == 'C'){
			sol += y;
		}
	}

	cout << sol << endl;
	
}	

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for(int i = 1; i <= n; i++){
		cout << "Case #" << i << ": ";
		solve();
	}
	
}
