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
	int a[26];
	memset(a, 0, sizeof(a));

	for(int i = 0; i < s.size(); i++){
		a[s[i]-'a'] = 1;
	}

	int sum = 0;
	for(int i = 0; i < 26; i++){
		sum += a[i];
	}

	if(sum % 2 == 1){
		cout << "IGNORE HIM!" << endl;
	}
	else{
		cout << "CHAT WITH HER!" << endl;
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
