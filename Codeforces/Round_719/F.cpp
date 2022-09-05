#include<bits/stdc++.h>
using namespace std;

#define ll long long
//1#define endl '\n'
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define F first;
#define S second;

void solve(){
  int n, t, k; cin >> n >> t >> k;
  int l = 0, r = n;
  while(l + 1 != r){
      int mid = (l + r) / 2;

    if(l == r){
          cout << "! " << l << endl;
      }

      cout << "? " << 1 << " " << mid << endl;

      int val; cin >> val;
      
      if((mid-val) < k){
          l = mid;
      }
      else{
          r = mid;
      }
  }
  
  cout << "! " << r << endl;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n = 1;
  while(n--){
    solve();
  }
}