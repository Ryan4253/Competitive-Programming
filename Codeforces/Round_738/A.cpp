#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define F first;
#define S second;

void solve(){
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
       cin >> a[i];
    }
    int sol = a[0];

    for(int i = 1; i < n; i++){
        sol = sol&a[i];
    }

    cout << sol << endl;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n = 1; cin >> n;
  while(n--){
    solve();
  }
}