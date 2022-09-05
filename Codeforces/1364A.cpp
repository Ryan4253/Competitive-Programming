#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

void solve(){
	int n, x; cin >> n >> x;
	int a[n], sum = 0;
	bool flag = false;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		sum += a[i];
		if(a[i] % x != 0){
			flag = true;
		}
	}
	int l = 0, r = n-1;
	if(!flag){
		cout << "-1" << endl;
	}
	else if(sum % x != 0){
		cout << n << endl;
	}
	else{
		while(a[l] % x == 0){
			l++;
		}
		while(a[r] % x == 0){
			r--;
		}
		cout << max(r, n-l-1) << endl;
	}
	
	
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		solve();
	}
}

