#include<bits/stdc++.h>
using namespace std;
int main(){
	int n; cin >> n;
	stack<int> sta;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		if(x == 1){
			int y; cin >> y;
			sta.push(y);
		}
		else{
			if(sta.empty()){
				cout << "empty!" << endl;
			}
			else{
				cout << sta.top() << endl;
				sta.pop();
			}
		}
	}
}

