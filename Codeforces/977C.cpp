#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

void solve(){
	int n, k; cin >> n >> k;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	sort(a, a+n);
	
	if(k == 0){
		if(a[0] == 1){
			cout << "-1" << endl; 
		}
		else{
			cout << a[0] - 1 << endl;
		}
	}
	else{
		if(a[k-1] == a[k]){
			cout << "-1" << endl;
		}
		else{
			cout << a[k-1] << endl;
		}
	}
	
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}

