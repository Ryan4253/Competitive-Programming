#include<bits/stdc++.h>
using namespace std;

int solve(){
	stack<int> sta;
	stack<int> end;
	int n; cin >> n; // car
	int a[n]; // arrangement
	for(int i = n; i > 1; i--){
		sta.push(i);
	}
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	end.push(1);
	for(int i = 0; i < n; i++){
		while(end.top() != a[i]){
			v 
			if(sta.empty()){
				cout << "No" << endl;
				return 0;
			}
			else{
				end.push(sta.top());
				sta.pop();
			}
		}
		end.pop();
		if(end.empty() && !sta.empty()){
			end.push(sta.top());
			sta.pop();
		}
	}
	cout << "Yes" << endl;
}

int main(){
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		solve();
	}
}
	

