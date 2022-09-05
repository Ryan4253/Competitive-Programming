#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

void solve(){
	int l, r; cin >> l >> r;
	if(l * 2 > r){
		cout << -1 << " " << -1 << endl;
		return;
	}

	cout << l << " " << l * 2 << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--){
		solve();
 	}
}
