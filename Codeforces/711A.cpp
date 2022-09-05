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
	bool flag = false;
	vector<string> sol;
	for(int i = 0; i < n; i++){
		string s; cin >> s;
		if(!flag && (s[0] == 'O' && s[1] == 'O' || s[3] == 'O' && s[4] == 'O')){
			flag = true;
			string edited;
			if(s[0] == 'O' && s[1] == 'O'){
				edited = "++|";
				edited += s[3];
				edited += s[4];
				sol.pb(edited);
			}
			else{
				edited = s[0];
				edited += s[1];
				edited += "|++";
				sol.pb(edited);
			}
		}
		else{
			sol.pb(s);
		}
	}

	if(flag){
		cout << "YES" << endl;
		for(int i = 0; i < n; i++){
			cout << sol[i] << endl;
		}
	}
	else{
		cout << "NO" << endl;
	}

	

}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
