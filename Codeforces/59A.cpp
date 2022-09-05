#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long;
#define pii paid<int, int>


void solve(){
	string s; cin >> s;
	int upper = 0, lower = 0;
	
	for(int i = 0; i < s.size(); i++){
		if(s[i] >= 65 && s[i] <= 90){
			upper++;
		}
		else{
			lower++;
		}
	}
	
	string sol = "";
	if(lower >= upper){
		for(int i = 0; i < s.size(); i++){
			if(s[i] <= 90){
				sol += s[i] + 32; 
			}
			else{
				sol += s[i];
			}
		}
	}
	else{
		for(int i = 0; i < s.size(); i++){
			if(s[i] >= 97){
				sol += s[i] - 32;
			}
			else{
				sol += s[i];
			}
		}
	}
	
	cout << sol << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n = 1;
	while(n--){
		solve();
 	}
}

