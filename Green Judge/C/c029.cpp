#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

void solve(){
	priority_queue<int, vector<int>, greater<int> > lmao;
	int n; cin >> n;
	int temp;
	for(int i = 0; i < n; i++){
		cin >> temp;
		lmao.push(temp);
	}
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> temp;
		lmao.push(temp);
	}
	
	while(!lmao.empty()){
		cout << lmao.top() << " ";
		lmao.pop();
	}
	
	cout << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}

