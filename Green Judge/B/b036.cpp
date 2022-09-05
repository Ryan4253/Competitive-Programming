#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

void solve(){
	priority_queue <int, vector<int>, greater<int> > slime;
	int n; cin >> n;
	int temp;
	for(int i = 0; i < n; i++){
		cin >> temp;
		slime.push(temp);
	} 
	int manareq = 0;
	int totalreq = 0;
	
	while(slime.size() != 1){
		manareq += slime.top();
		slime.pop();
		manareq += slime.top();
		slime.pop();
		
		totalreq += manareq;
		slime.push(manareq);
		manareq = 0;
	}
	
	cout << totalreq << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}

