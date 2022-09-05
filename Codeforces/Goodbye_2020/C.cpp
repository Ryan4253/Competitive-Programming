#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

int use[100000 + 5];

void solve(){
	string s; cin >> s;
	
	int sol = 0;
	int length = s.size();
	for(int i = 0; i < length-2; i++){
		if(use[i]){
			continue;
		}

		if(s[i] == s[i+2]){
			if(s[i] == s[i+1]){
				sol += 2;
			}
			else{
				sol++;
			}
			
			use[i] = 1;
			use[i+1] = 1;
			use[i+2] = 1;
		}
	}
	
	
	for(int i = 0; i < length-1; i++){
		
		if(use[i] || use[i+1]){
			continue;
		}

		if(s[i] == s[i+1]){
			sol++;
			use[i]=1;
			use[i+1]=1;
		}
	}
	
	cout << sol << endl;
	
	for(int i = 0; i <= length; i++){
		use[i] = 0;
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--){
		solve();
	}
}
