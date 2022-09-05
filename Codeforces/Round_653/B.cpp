#include<bits/stdc++.h>
using namespace std;

int solve(){
	int n; cin >> n;
	int cnt = 0;
	while(n != 1){
		if(n % 6 == 0){
			n /= 6;
			cnt ++;
		}
		else if (n % 3 == 0){
			n *= 2;
			cnt ++;
		}
		else{
			cout << "-1" << endl;
			return 0;
		}
	}
	cout << cnt << endl;
}
int main(){
	int n = 0; cin >> n;
	for(int i = 0; i < n; i++){
		solve();
	}
}

