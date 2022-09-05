#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve(){
	priority_queue<int, vector<int>, greater<int> > min_heap; 
	int t; cin >> t;
	int a, b;
	for(int i = 0; i < t; i++){
		cin >> a;
		if(a == 1){
			cin >> b;
			min_heap.push(b);
		}
		else{
			if(min_heap.empty()){
				cout << "EMPTY!" << endl;
				continue;
			}
			else{
				cout << min_heap.top() << endl;
				min_heap.pop();
			}
		}
	}
} 
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}

