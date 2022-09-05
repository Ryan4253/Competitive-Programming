#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second

const int N = 205;
int dp[N][N][N];

void update(int &a, int b){
    a = max(a, b);
}

void solve(){
	int n, kk; cin >> n >> kk;
    string s; cin >> s;
    string t; cin >> t;
    s = " " + s;
    memset(dp, -1, sizeof(dp));
    dp[1][0][0] = 0;
    
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= kk; j++){
            for(int k = 0; k <= n; k++){
                if (dp[i][j][k] == -1){
                    continue;
                }
                //Case 1, don't change
                update(dp[i+1][j][k+(s[i] == t[0])], dp[i][j][k] + (s[i] == t[1]) * k);
                //Case 2, change s[i] to t[0]
                update(dp[i+1][j+1][k+1], dp[i][j][k] + (t[0]==t[1]) * k);
                //Case 3, change s[i] to t[1]
                update(dp[i+1][j+1][k+(t[0]==t[1])], dp[i][j][k] + k);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i <= kk; i++){
        for(int j = 0; j <= n; j++){
            ans = max(dp[n+1][i][j], ans);
        }
    }
    
    cout << ans << endl;
    
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n = 1;
	while(n--){
		solve();
 	}
}
