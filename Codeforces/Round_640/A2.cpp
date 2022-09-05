#include<bits/stdc++.h>
using namespace std;

void solve1(int n){
	int cnt = 0;
	while(n != 0){
		if(n % 10 != 0){
			cnt ++;
		}
		n /= 10;
	} 
	cout << cnt << endl;
}

void solve2(int n){
	int power = 0;
	while(n != 0){
		if(n % 10 != 0){
			cout << n % 10 * pow(10, power) << " ";
		}
		n /= 10;
		power ++;
	}
	cout << endl;
}

int main(){
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		solve1(x);
		solve2(x);
	}
}

