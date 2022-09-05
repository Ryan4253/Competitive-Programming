#include<iostream>
#include<queue>
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
	
	int totaltime = 0;
	int crytime;
	
	while(!lmao.empty()){
		crytime = lmao.top();
		lmao.pop();
		
		totaltime += lmao.size() * crytime;
	}
	
	cout << totaltime * 100 << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}

