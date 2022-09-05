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
	string s; cin >> s;
	int a[26];
	memset(a, 0, sizeof(a));

	for(int i = 0; i < n; i++){
		if(s[i] >= 97){
			a[s[i]-97] = 1;
		}
		else{
			a[s[i]-65] = 1;
		}
	}

	sort(a, a + 26);

	if(a[0]){
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
