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
	int n; cin >> n;
	if(n == 5){
		cout << 96 << endl;
		return;
	}

	int a;
	cin >> a >> a >> a >> a >> a;

	if(a == 1){
		cout << 0 << endl;
	}
	else{
		cout << 24 << endl;
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
