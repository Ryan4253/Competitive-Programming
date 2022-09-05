#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

const int N = 100 + 5;
const int X = 1000000 + 5;
int weight[N];
int worth[N];
int dp[2][X];
void DP(int n, int m){
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(j-weight[i] < 0){
                dp[i & 1][j] = dp[(i-1) & 1][j];
            }
            else{
                dp[i & 1][j] = max(dp[(i-1) & 1][j], dp[ (i-1) & 1][j-weight[i]]+worth[i]);
            }
            dp[i & 1][j] = max(dp[i & 1][j], dp[i & 1][j - 1]);
        }     
    }
}

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> weight[i] >> worth[i];
    }
    DP(n, m);
    
    cout << dp[n & 1][m] << endl;
    memset(dp, 0, sizeof(dp));
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); 
    int n; cin >> n;
    while(n--){
        solve();
    }
}
