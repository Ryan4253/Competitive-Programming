#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

const int N = 26;
int a[N];

void solve(){
	int n; cin >> n;
	string s[n];
	
	for(int i = 0; i < n; i++){
		cin >> s[i];
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < s[i].size(); j++){
			a[s[i][j]-97]++;
		}
	}
	
	
    bool flag= true;
	for(int i = 0; i < 26; i++){
		if(a[i] % n != 0){
			flag = false;
		}
	}
	
	if(flag){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl; 
	}
	
	for(int i = 0; i < 26; i++){
		a[i] = 0;
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--){
		solve();
	}
}

