#include<bits/stdc++.h>
using namespace std;

void solve(){
	int x, y, n; cin >> x >> y >> n;
	//k % x = 7
	int remainder = 0;
	remainder = n % x;
	if(remainder >= y){
		cout << n - (remainder - y) << endl;
	}
	else{
		cout << n - (x - (y - remainder)) << endl;
	}
}
int main(){
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		solve();
	}
}

