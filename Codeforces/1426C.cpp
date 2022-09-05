#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

int check(int i, int n){
	int dupe = i + 1;
	return n / dupe + !(n % dupe == 0) + i;
}

void solve(){
	int n; cin >> n;

	int sol = 2000000000;

	for(int i = 0; i <= sqrt(n) + 5; i++){
		sol = min(sol, check(i, n));
	}

	cout << sol-1 << endl;

}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--){
		solve();
 	}
}
