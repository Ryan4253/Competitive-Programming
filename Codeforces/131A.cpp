#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

void solve(){
	string s; cin >> s;
	bool stuff = true;
	for(int i = 1; i < s.size(); i++){
		if(s[i] >= 'a'){
			stuff = false;
		}
	}
	
	if(stuff == true){
		for(int i = 0; i < s.size(); i++){
			if(s[i] >= 'a'){
				s[i] -= 32;
			}
			else{
				s[i] += 32;
			}
		}
	}
	
	cout << s << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}

