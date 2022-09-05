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
  int a, b, c, d; cin >> a >> b >> c >> d;
    int n[4] = {a, b, c, d};
    sort(n, n + 4, greater<int>());
    if((n[0] == a || n[0] == b) && (n[1] == c || n[1] == d)){
        cout << "YES" << endl;
    }
    else if((n[0] == c || n[0] == d) && (n[1] == a || n[1] == b)){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
  
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n = 1; cin >> n;
  while(n--){
    solve();
  }
}