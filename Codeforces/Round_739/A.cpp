#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define F first;
#define S second;

const int N = 2005;
int dp[N];
int ptr = 0;

void DP(){
    int curr_val = 1;
    int cnt = 0;

    while(cnt != 1002){
        if(curr_val % 3 == 0 || curr_val % 10 == 3){

        }
        else{
            dp[cnt] = curr_val;
            cnt++;
        }
        curr_val++;
    }
}

void solve(){
    int n; cin >> n;
    cout << dp[n-1] << endl;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  DP();
  int n = 1; cin >> n;
  while(n--){
    solve();
  }
}