#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

void solve(){
	int n; cin >> n;
	string s; cin >> s;
	
	int flag = 2147483647;
	for(int i = 0; i < n; i++){
		if(s[i] == '1'){
			flag = i;
			break;
		}
	}
	
	string large = "", small = "";
	
	for(int i = 0; i < n; i++){
		if(i <= flag){
			large += (s[i]-47)/2 + 48;
			small += (s[i]-48)/2 + 48;
		}
		else{
			large += '0';
			small += s[i];
		}
	}
	cout << large << endl << small << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++){
		solve();
	}
}

