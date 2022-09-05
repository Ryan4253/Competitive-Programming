#include<bits/stdc++.h>
using namespace std;

void math(){
	int n, k; cin >> n >> k;
	if(k > n){
		cout << "NO" << endl;
		return;
	}
	
	if((n - k + 1)%2 == 1){
		cout << "YES" << endl;
		for(int i = 0; i < k - 1; i++){
			cout << "1" << " ";
		}
		cout << n - k + 1 << endl;
		return;
	}
	
	if((n - 2 * k + 2)%2 == 0 && n - 2 * k + 2 > 0){
		cout << "YES" << endl;
		for (int i = 0; i < k-1; i++){
			cout << "2" << " ";
		}
		cout << n - 2 * k + 2 << endl;
		return;
	}
		cout << "NO" << endl;
		return;
}


int main(){
	int t; cin >> t;
	for(int i = 1; i <= t; i++){
		math();
	}
}

