#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n; cin>> n;
	string s; cin >> s;
	stack<int> sta;
	int a[n];
	
	for(int i = 0; i < n; i++){
		if(s[i] == '('){
			a[i] = 1;
		}
		else{
			a[i] = 0;
		}
	}
	
	sta.push(a[n-1]);
	for(int i = n-2; i >= 0; i--){
		if(a[i] == 1){
			if(sta.empty()){
				sta.push(1);
			}
			else if(sta.top() == 0){
				sta.pop();
			}
			else{
				sta.push(1);
			}
		}
		else{
			sta.push(0);
		}
	}
	int cnt = 0;
	while(!sta.empty()){
		
		if(sta.top() == 1){
			cnt++;
		}
		sta.pop();
	}	
	cout << cnt << endl;
}

int main(){
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		solve();
	}
}

