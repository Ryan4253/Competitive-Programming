#include<bits/stdc++.h>
using namespace std;
int main(){
	int n; cin >> n;
	queue<int> que;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		if(x == 1){
			int y; cin >> y;
			que.push(y);
		}
		else{
			if(que.empty()){
				cout << "empty!" << endl;
			}
			else{
				cout << que.front() << endl;
				que.pop();
			}
		}
	}
}

