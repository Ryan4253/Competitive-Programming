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
		


		if(s[0] == '2' && s[1] == '0' && s[2] == '2' && s[n-1] == '0'){
			cout << "YES" << endl;
		}
		else if(s[0] == '2' && s[n-3] == '0' && s[n-2] == '2' && s[n-1] == '0'){
			cout << "YES" << endl;
		}
		else if(s[0] == '2' && s[1] == '0' && s[n-2] == '2' && s[n-1] == '0'){
			cout << "YES" << endl;
		}
		else if(s[0] == '2' && s[1] == '0' && s[2] == '2' && s[3] == '0'){
			cout << "YES" << endl;
		}
		else if(s[n-4] == '2' && s[n-3] == '0' && s[n-2] == '2' && s[n-1] == '0'){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}

	}

	int main(){
		ios::sync_with_stdio(0); cin.tie(0);
		int n; cin >> n;
		while(n--){
			solve();
	 	}
	}
