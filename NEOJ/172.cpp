#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

const int N = 200 + 5;
const int X = 1000007;
ll int C[N][N];
ll int dp[N][N];
int a[N];

void comb(){
    for(int i = 0; i < N; i++){
        C[i][0] = 1;
        C[i][i] = 1;
    }
    // C[i][1] ~ C[i][i - 1]
    for(int i = 1; i < N; i++){
        for(int j = 1; j <= i-1; j++){
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % X;
        }
    }
}

void DP(int n, int m){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			dp[i][j] = 0;
		}
	}
	dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            for(int k = 0; k <= a[i]; k++){
                if(m - (j-k) < 0 || j-k < 0){
                    continue;
                }
                dp[i][j] += (dp[i-1][j-k] * C[m-(j-k)][k] * C[j-k][a[i]-k]) % X;
                dp[i][j] %= X;
            }
        }
    }
}



void solve(){
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    comb();
    DP(n, m);
    
    cout << dp[n][m] << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    while(n--){
        solve();
    }
}
