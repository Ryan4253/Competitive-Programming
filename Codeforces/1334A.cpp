#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

void solve(){
	int n; cin >> n;
	int p[n];
	int c[n];
	for(int i = 0; i < n; i++){
		cin >> p[i] >> c[i];
	}
	
	bool flag = true;
	
	for(int i = 0; i < n; i++){
		if(i >= 1){
			if(c[i] < c[i-1]){
				flag = false;
			}
			if(p[i] < p[i-1]){
				flag = false;
			}
			if(c[i] - c[i-1] > p[i] - p[i-1]){
				flag = false;
			}
		} 
		if(c[i] > p[i]){
			flag = false;
		}
	}
	
	if(flag){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		solve();
	}
}


