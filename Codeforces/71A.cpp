#include<bits/stdc++.h>
using namespace std;

void solve(){
	string s; cin >> s;
	if(s.size() > 10){
		cout << s[0] << s.size()-2 << s[s.size()-1] << endl;
	}
	else{
		cout << s << endl;
	}
}

int main(){
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		solve();
	}
}

