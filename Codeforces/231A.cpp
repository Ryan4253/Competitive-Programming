#include<bits/stdc++.h>
using namespace std;
int solution = 0;

void solve(){
	int a, b, c; cin >> a >> b >> c;
	int cnt = 0;
	if(a == 1){
		cnt++;
	}
	if(b == 1){
		cnt++;
	}
	if(c == 1){
		cnt ++;
	}
	if(cnt > 1){
		solution++;
	}
}
int main(){
	int n = 0; cin >> n;
	for(int i = 0; i < n; i++){
		solve();
	}
	cout << solution << endl;
}

