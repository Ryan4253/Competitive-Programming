#include<iostream>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

const int N = 100 + 1;
ll int a[N];
ll int dp[N];

void lis(int n){
    dp[1] = 1;
    
    for(int i = 2; i <= n; i++){
        dp[i] = 1;
        for(int j = 1; j < i; j++) {
            if(a[j] < a[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            } 
        }
    }
}

void solve(){
    
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    lis(n);
    ll int mx = 1;
    for(int i = 1; i <= n; i++){
        mx = max(dp[i], mx);
    }
    cout << mx << endl;
    
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
    solve();
}
