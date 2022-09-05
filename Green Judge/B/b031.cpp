#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

const int N = 100 + 1;
const int M = 1000 + 1;
int weight[N];
int worth[N];
int dp[N][M];

void DP(int n, int m){
	for(int i = 0; i <= n; i++){
		dp[i][0] = 0;	
	}
	for(int i = 1; i <= m; i++){
		dp[0][i] = -1;
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			dp[i][j] = dp[i-1][j];
			if(j >= weight[i]){
				dp[i][j] = max(dp[i][j-weight[i]] + worth[i], dp[i][j]);
			}	
		}
	}
}

void solve(){
	int n, m; cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> weight[i] >> worth[i];
	}
	DP(n, m);
	int sol = 0;
	for(int i = 1; i <= m; i++){
		sol = max(sol, dp[n][i]);
	}
	cout << sol << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
