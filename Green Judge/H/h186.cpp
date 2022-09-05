#include<iostream>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second


void solve(){
	ll int n, m; cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y; cin >> x >> y;
	}

	if((n * (n-1) / 2) == m){
		cout << "0" << endl;
	}
	else{
		cout << n << endl;
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--){
		solve();
 	}
}
