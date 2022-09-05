#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long;
#define pii paid<int, int>


void solve(){
	string s1, s2; cin >> s1 >> s2;
	reverse(s1.begin(), s1.end());
	
	if(s1 == s2){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n = 1;
	while(n--){
		solve();
 	}
}

