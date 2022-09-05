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
	if(a == b){
		cout << 0 << endl;

	}
	else if(a > b && (a - b) % 2 == 1 || a < b && (b - a) % 2 == 0){
		cout << 2 << endl;
	}
	else{
		cout << 1 << endl;
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--){
		solve();
 	}
}
