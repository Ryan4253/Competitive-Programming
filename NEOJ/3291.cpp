#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

void solve(){
	int x; cin >> x;
	int n; cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	if(accumulate(a, a+n, 0) == x){
		cout << "WIN" << endl;
	}
	else{
		cout << "LOSE" << endl;
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for(int i = 0 ; i < n; i++){
		solve();
	}
}

