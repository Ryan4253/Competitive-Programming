#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

//0 = red, 1 = green, 2 = blue
const int N = 100000 + 5;
const int X = 1000007;
int a[N];
int dp[N][3][3];

void DP(){
	dp[1][0][0] = 1;
    dp[1][1][1] = 1;
    dp[1][2][2] = 1;
    
    for(int i = 2; i < N; i++){
        for(int j = 0; j < 3; j++){
            dp[i][j][0] = (dp[i-1][j][0] + dp[i-1][j][1] + dp[i-1][j][2]) % X;
            dp[i][j][1] = (dp[i-1][j][0] + dp[i-1][j][1]) % X;
            dp[i][j][2] = (dp[i-1][j][0] + dp[i-1][j][2]) % X;
        }
    }
}

void solve(){
    int n; cin >> n;
    
    int sol = (dp[n][0][0] + dp[n][0][1] + dp[n][0][2] + dp[n][1][0] + dp[n][1][1] + dp[n][2][0] + dp[n][2][2]) % X;
    
    cout << sol << endl;
}

int main(){
	DP();
	ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        solve();
    }
}
