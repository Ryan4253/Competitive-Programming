#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

void solve(){
	int n; cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	sort(a, a+n);
	
	int diff[n-1];
	for(int i = 0; i < n-1; i++){
		diff[i] = a[i+1] - a[i];
	}
	bool flag = true;
	for(int i = 0; i < n-1; i++){
		if(diff[i] != 1 && diff[i] != 0){
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
	while(n--){
		solve();
	}
}

