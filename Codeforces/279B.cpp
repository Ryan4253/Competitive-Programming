#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

void solve(){
	int n, t; cin >> n >> t;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	sort(a, a+n);
	int temp = 0;
	
	for(int i = 0; i < n; i++){
		temp += a[i];
		if(temp > t){
			cout << i << endl;
			return;
		}
	}
	
	cout << n << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}

