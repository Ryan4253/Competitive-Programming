#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

const int N = 200000 + 5;
int dp[N];

void solve(){
    int n, m, k; cin >> n >> m >> k;
    dp[n-k] = 0;
    for(int i = n-k + 1; i <= n; i++){
        dp[i] = (dp[i-1] + m) % i;
    }
    
    cout << dp[n] + 1 << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n = 1;
	while(n--){
		solve();
 	}
}
