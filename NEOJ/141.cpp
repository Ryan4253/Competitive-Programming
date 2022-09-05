#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

const int N = 100000 + 5;
int dp[N]; 
int a[N];

void DP(int n){
	dp[0] = 0, dp[1] = a[0], dp[2] = max(a[0], a[1]);
	
	for(int i = 3; i <= n; i++){
		dp[i] = max(dp[i-2], dp[i-3]) + a[i-1];
	}
}

void solve(){
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	DP(n);
	cout << max(dp[n], dp[n-1]) << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--){
		solve();
	}
}

