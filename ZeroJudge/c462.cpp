#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

int letter(char s){
	if(s >= 'A' && s <= 'Z'){
		return 0;
	}
	else{
		return 1;
	}
}

void solve(){
	int n; cin >> n;
	string s; cin >> s;
	vector<int> v;
	int cnt = 1;
	for(int i = 1; i < s.size(); i++){
		if(letter(s[i]) != letter(s[i-1])){
			v.pb(cnt);
			cnt = 1;
		}
		else{
			cnt++;
		}
	}
	v.pb(cnt);

	int sol = 0;
	int count = -1;

	for(int i = 0; i < v.size(); i++){
		if(v[i] == n && count == -1){
			if(i > 0 && v[i-1] > n){
				count = 2;
			}
			else{
				count = 1;
			}
		}
		else if(v[i] == n){
			count++;
		}
		else if(v[i] != n && i > 0 && v[i-1] == n){
			if(v[i] > n){
				count++;
			}
			sol = max(sol, count);
			count = -1;
		}
	}

	sol = max(sol, count);

	cout << sol * n << endl;


}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
