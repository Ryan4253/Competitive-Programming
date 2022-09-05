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
    int base = n/3;
    n %= 3;

    if(n == 0){
        cout << base << " " << base << endl;
    }
    else if(n == 1){
        cout << base + 1 << " " << base << endl;
    }
    else{
        cout << base << " " << base + 1 << endl;
    }

}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n = 1; cin >> n;
  while(n--){
    solve();
  }
}