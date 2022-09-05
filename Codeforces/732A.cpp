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
	int k, r; cin >> k >> r;

	int n = 1;
	while(true){
		int cost = n * k;

		if((cost - r) % 10 == 0 || cost % 10 == 0){
			cout << n << endl;
			return;
		}
		n++;
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
