#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

const int N = 100+5;
const int X = 7;
int dp[X][N];
int weight[X] = {0, 1, 5, 10, 12, 16, 20};
void DP(){
    for(int i = 0; i < X; i++){
        dp[i][0] = 0;
    }
    for(int i = 1; i < N; i++){
        dp[0][i] = 101;
    }
    
    for(int i = 1; i < X; i++){
        for(int j = 1; j < N; j++){
            dp[i][j] = dp[i-1][j];
            for(int k = 1; k*weight[i] <= j; k++){
                dp[i][j] = min(dp[i-1][j-k*weight[i]]+k, dp[i][j]);
            }
        }
    }
}

void solve(){
    int n; cin >> n;
    DP();
    cout << dp[6][n] << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
    solve();
}
