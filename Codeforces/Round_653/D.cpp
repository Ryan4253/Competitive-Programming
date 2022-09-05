#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n, k; cin >> n >> k;
	int a[n];
	
	for(int i = 0; i < n; i++){
		cin >> a[i];
		a[i] = k - (a[i] % k);
	}
	
	int sol[k];
	for(int i = 0; i < k; i++){
		sol[i] = 0;
	}
	for(int i = 0; i < n; i++){
		sol[(a[i])]++;
	}
	int max = 0, ptr = 0;
	for(int i = 0; i < k; i++){
		if(sol[i] >= max){
			max = sol[i];
			ptr = i;
		}
	}

	cout << k * (max-1) + ptr + 1 << endl;
}

int main(){
	int t; cin >> t;
	for(int i = 0; i < t; i++){
		solve();
	}
}

