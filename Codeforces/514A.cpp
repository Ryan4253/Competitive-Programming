#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

void solve(){
	string s; cin >> s;
	int i = 0;
	if(s[0] == '9'){
		i = 1;
	}
	for(i ; i < s.size(); i++){
		if(s[i] >= '5'){
			s[i] = 105-s[i];	
		}
	}
	
	cout << s << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}

