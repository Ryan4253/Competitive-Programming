#include<bits/stdc++.h>
using namespace std;

//#define endl '\n'
#define ll long long
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define pb push_back
#define pog ios::sync_with_stdio(0);
#define champ cin.tie(0);
#define inf 2147483647

const int N = 10000 + 5;;
const int M = 50 + 5;
int a[M][N];
int dp[M][N][3]; // 1 == top, 

void DP(int n, int m){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			dp[i][j][0] = max({dp[i-1][j][0], dp[i-1][j][1], dp[i-1][j][2]}) + a[i][j];
		}

		for(int j = 1; j <= m; j++){
			dp[i][j][1] = max(dp[i][j-1][1]+a[i][j], dp[i][j][0]);
		}

		for(int j = m; j >= 1; j--){
			dp[i][j][2] = max(dp[i][j+1][2]+a[i][j], dp[i][j][0]);
		}
	}
}

void solve(){
	int n, m; cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> a[i][j];
		}
	}

	DP(n, m);

	int sol = -inf;

	
	for(int i = 1; i <= m; i++){
		int mx = max({dp[n][i][0], dp[n][i][1], dp[n][i][2]});
		sol = max(sol, mx);
	}

	cout << sol << endl;
}

int main(){
	pog champ
	solve();
}