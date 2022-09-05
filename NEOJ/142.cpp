#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

const int N = 1000 + 5;
int a[N];
int dp[N];

void DP(int n, int k){
	dp[0] = 0; dp[1] = a[1];
	for(int i = 2; i <= k; i++){
		dp[i] = max(dp[i-1], a[i]);
	}
	int mx;
	for(int i = k + 1; i <= n; i++){
		mx = 0;
		for(int j = i - 2*k + 1; j <= i-k; j++){
			if(j <= 0){
				continue;
			}
			mx = max(mx, dp[j]);
		}
		dp[i] = mx + a[i];
	}
}

void solve(){
	int n, k; cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	DP(n, k);
	int sol = 0;
	for(int i = 1; i <= n; i++){
		sol = max(sol, dp[i]);
	}
	cout << sol << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--){
		solve();
	}
}

