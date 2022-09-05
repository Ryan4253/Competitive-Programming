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
	int sol = 0;
	for(int i = 1; i <= n; i++){
		if(n % i == 0){
			sol++;
		}
	}

	cout << sol-1 << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
