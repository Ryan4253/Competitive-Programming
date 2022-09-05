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
	int a, b; cin >> a >> b;
	if(a == 1){
		cout << 0 << endl;
	}
	else if(a == 2){
		cout << b << endl;
	}
	else{
		cout << 2 * b << endl;
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--){
		solve();
 	}
}
