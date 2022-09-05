#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define F first;
#define S second;

const int N = 1000000 + 5;
int a[N];
int b[N-1];
const ll int mod = 1000000009;
void solve(){
  int n; cin >> n;
  for(int i = 0; i < n;  i++){
      cin >> a[i];
  }


  ll int sol = 1;
  
  for(int i = 0; i < n-1; i++){
      b[i] = a[i+1]-a[i];
  }

  for(int i = 0; i < n-1; i++){
      sol *= (b[i]);
      sol %= mod;
      if(sol < 0){
        sol += mod;
     }
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