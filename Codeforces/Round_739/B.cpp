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
    int a, b, c; cin >> a >> b >> c;
    if(a > b){
        swap(a, b);
    }

    pii res = mp(1, b-a+1);
    int num = res.second*2-2;

    if(b > num || c > num){
        cout << -1 << endl;
    }
    else{
        if(c < res.second){
            cout << res.second + c - 1 << endl;
        }
        else{
            cout << 1 + c - res.second << endl;
        }
    }
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n = 1; cin >> n;
  while(n--){
    solve();
  }
}