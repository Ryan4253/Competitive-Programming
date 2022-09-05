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
	string s; cin >> s;
	int cnt = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '4' || s[i] == '7'){
			cnt++;
		}
	}


	if(cnt == 7 || cnt == 4){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
