#include<bits/stdc++.h>
using namespace std;
int main(){
	int n = 0; cin >> n;
	stack<int> sta;

	for(int i = 0; i < n; i++){
		int x = 0; cin >> x;
		if(x > 0){
			sta.push(x);
		}
		else if(sta.empty() && x < 0){
			cout << "lose light light" << endl;
			return 0;	
			}
		else if(-x == sta.top()){
			sta.pop();
		}
		else{
			cout << "lose light light" << endl;
			return 0;
			}
}
	if(sta.empty()){
			cout << "weed" << endl;
		}
		else{
			cout << "lose light light" << endl;
		}
}

