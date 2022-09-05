#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

const int N = 1000000 + 5;
int a[N];

void solve(){
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	ll int sol = 0;
	sort(a, a + n, greater<int>());
	for(int i = 0; i < n; i++){
		sol += (a[0]-a[i]);
	}

	cout << sol << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
