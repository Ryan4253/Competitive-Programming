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
	int a[n];

	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	sort(a, a + n);

	int diff = 10000;
	for(int i = 1; i < n; i++){
		diff = min(diff, a[i] - a[i-1]);
	}

	cout << diff << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--){
		solve();
 	}
}
