#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

void solve(){
	int n; cin >> n;
	string s; cin >> s;
	vector<int> v;
	
	for(int i = 0; i < n; i++){
		if(s[i] == '2'){
			v.pb(2);
		}
		if(s[i] == '3'){
			v.pb(3);
		}
		if(s[i] == '4'){
			v.pb(3);
			v.pb(2);
			v.pb(2);
		}
		if(s[i] == '5'){
			v.pb(5);
		}
		if(s[i] == '6'){
			v.pb(5);
			v.pb(3);
		}
		if(s[i] == '7'){
			v.pb(7);
			
		}
		if(s[i] == '8'){
			v.pb(7);
			v.pb(2);
			v.pb(2);
			v.pb(2);
		}
		if(s[i] == '9'){
			v.pb(7);
			v.pb(3);
			v.pb(3);
			v.pb(2);
		}
	}
	sort(v.begin(), v.end(), greater<int>());
	
	for(int i = 0; i < v.size(); i++){
		cout << v[i];
	}
	cout << endl;
	
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}

