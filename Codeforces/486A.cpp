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
	ll int n; cin >> n;
	if(n % 2 == 0){
		cout << n / 2 << endl;
	}
	else{
		cout << n/2 - n << endl;
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
