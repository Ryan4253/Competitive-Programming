#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

const int N = 100 + 2;
int dp[N][N];
string a, b;

void DP(){
    for(int i = 1; i < a.size(); i++){
        for(int j = 1; j < b.size(); j++){
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if(a[i] == b[j]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
        }
    }
}

void solve(){
    cin >> a >> b;
    a = " " + a, b = " " + b;
    DP();
    cout << dp[a.size()-1][b.size()-1] << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
    solve();
}
