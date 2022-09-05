
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define F first;
#define S second;

const int N = 100000 + 5;
ll int a[N];
ll int dp[N];
deque<pair<ll, ll> > deq; // position, value

// dp[n] = a[n] + max(dp[i] - c * (n-i)), n-k to n-1
// dp[n] = a[n] + max(dp[i] - cn + ci);
// dp[n] = a[n] - cn + max(dp[i]+ci);
// dp[n] = a[n] + max(dp[i] - ci);

void remove(int pos, int k){
    while(!deq.empty()){
        if(deq.front().first < pos-k){
            deq.pop_front();
        }
        else{
            break;
        }
    }
}

void add(int i, int dp, int c){
    while(!deq.empty()){
        if((dp + c * i) > deq.back().second){
            deq.pop_back();
        }
        else{
            break;
        }
    }
    deq.push_back(make_pair(i, dp + c * i));
}

void solve(){
    int n, k, c; cin >> n >> k >> c;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    add(0, a[0], c);
    dp[0] = a[0];

    for(int i = 1; i < n; i++){
        remove(i, k);
        dp[i] = max(deq.front().second + a[i] - c * i, a[i]);
        add(i, dp[i], c);
    }
    
    ll int sol = 0;
    for(int i = 0; i < n; i++){
        sol = max(dp[i], sol);
    }
    
    cout << sol << endl;

    for(int i = 0; i < n; i++){
        a[i] = 0;
        dp[i] = 0;
    }

    while(!deq.empty()){
        deq.pop_back();
    }
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n = 1; cin >> n;
  while(n--){
    solve();
  }
}
