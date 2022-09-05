#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

void solve(){
	int n; cin >> n;
	string s; cin >> s;
	
	int cnt0 = 0, cnt1 = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == '1'){
			break;
		}	
		else{
			cnt0++;
		}
	}
	
	reverse(s.begin(), s.end());
	
	for(int i = 0; i < n; i++){
		if(s[i] == '0'){
			break;
		}
		else{
			cnt1++;
		}
	}
	
	for(int i = 0; i < cnt0; i++){
		cout << "0";
	}
	if(cnt1 + cnt0 != n){
		cout << "0";
	}
	for(int i = 0; i < cnt1; i++){
		cout << "1";
	}
	
	cout << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		solve();
	}	
}

