#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

void solve(){
	string s; cin >> s;
	reverse(s.begin(), s.end());
	int odd = 0, even = 0;
	for(int i = 0; i < s.size(); i++){
		if(i % 2 == 0){
			odd += s[i]-48;
		}
		else{
			even += s[i]-48;
		}
	}
	
	cout << max(odd, even) - min(odd, even) << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}

