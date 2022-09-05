#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define mp make_pair
#define F first;
#define S second;

ll int getArea(int n){
    ll int sol = 0;
    for(int i = 0; i < n; i++){
        sol += (n * n) - 2 * (i * (n-i));
    }
    return sol;
}

void solve(){
    int n, m; cin >> n >> m;
    ll int sol = 0;
    for(int i = 1; i <= min(n, m); i++){
        ll int a = getArea(i);
        sol += (a * (n-i) * (m-i));
    }
    cout << sol << endl;

}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n = 1;
  while(n--){
    solve();
  }
}