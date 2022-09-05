#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

const int N = 16 + 1;
int dp[N][1<<N];
int a[N][N];
//void clear(int n){for(int i = 0; i < n; i++){a[i] = 0;}}

void solve(){
	int n; cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int x; cin >> x;
            a[i][j] = x;
            a[j][i] = x;
        }
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < (1<<N); j++){
            dp[i][j] = 1000000000;
        }
    }
    
    dp[0][0] = 0;
    
    for(int mask = 0; mask < (1<<n); mask++){
        for(int j = 0; j < (n); j++){
            for (int k = 0; k < n; ++k) {
                if (((1 << k) & mask) == 0)
                    dp[k][mask | (1 << k)] = min(dp[k][mask | (1 << k)], dp[j][mask] + a[j][k]);
            }  
        }
    }
    
    cout << dp[0][ (1 << n) - 1 ] << endl;
    
    
    
    
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--){
		solve();
	}
}