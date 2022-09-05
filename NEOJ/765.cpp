#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

void solve(){
	int n; cin >> n;
	if(n == 2){
		cout << "1" << endl;
		return;
	}
	
	int book[n-1];
	int diff[n-2];
	int now, pre;
	for(int i = 0; i < n-1; i++){
		cin >> now;
		book[i] = now;
		if(i != 0){
			diff[i-1] = now - pre;
		}
		pre = now;
	}
	
	for(int i = 0; i < n-2; i++){
		
	} 
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}

