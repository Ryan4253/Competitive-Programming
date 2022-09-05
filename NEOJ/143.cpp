#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

const int N = 100 + 5;
int a[N];
int dp[N][N];
int n;

void DP(){
    for(int i = 1; i < N; i++){
        dp[i][i] = 0;
    }
    
    for(int length = 1; length <= n; length++){
        for(int l = 1; l <= n; l++){
            int r = length + l;
            if(r > n){
                break;
            }
            
            int cost = 0;
            int mincost = 1000000;
            
            for(int j = l; j < r; j++){
                cost = dp[l][j] + dp[j+1][r];
                mincost = min(mincost, cost);
            }
            dp[l][r] = mincost + accumulate(a+l, a+r+1, 0);
        }
    }
}


void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    DP();
    cout << dp[1][n] << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        solve();
    }
}
