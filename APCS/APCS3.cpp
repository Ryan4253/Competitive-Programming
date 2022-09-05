#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

const int N = 10000 + 5;
int a[55][N];
int dp[55][N][3];

void DP(int m, int n){
	for(int i = 0; i < m; i++){
		if(i == 0){
			for(int j = 0; j < n; j++){
				dp[i][j][0] = a[i][j];
			}
		}
		else{
			for(int j = 0; j < n; j++){
				dp[i][j][0] = max(dp[i-1][j][0], max(dp[i-1][j][1], dp[i-1][j][2])) + a[i][j];
			}
		}

		dp[i][0][1] = dp[i][0][0];
		dp[i][n-1][2] = dp[i][n-1][0];


		for(int j = 1; j < n; j++){
			dp[i][j][1] = max(dp[i][j-1][1] + a[i][j], dp[i][j][0]);
		}

		for(int j = n-1; j >= 0; j--){
			dp[i][j][2] = max(dp[i][j+1][2] + a[i][j], dp[i][j][0]);
		}
	}
}

void solve(){
	int n, m; cin >> m >> n;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
		}
	}

	DP(m, n);
	int sol = 0;

	
	for(int j = 0; j < n; j++){
		sol = max(sol, dp[m-1][j][0]);
		sol = max(sol, dp[m-1][j][1]);
		sol = max(sol, dp[m-1][j][2]);
	}
	

	cout << sol << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
