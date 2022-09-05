#include<bits/stdc++.h>
using namespace std;

#define ll long long
//#define endl '\n'
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define F first;
#define S second;

vector<int> v;

void solve(){
    int n; cin >> n;
    for(int i = 0; i < v.size(); i++){
        if(n < v[i]){
            cout << i << endl;
            return;
        }
    }


}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

    int a[10] = {1, 11, 111, 1111, 11111, 111111, 1111111, 11111111, 111111111};

    for(int i = 0; i < 9; i++){
        for(int j = 1; j <= 9; j++){
            v.pb(a[i] * j);
        }
    }
    v.pb(1111111111);

    sort(v.begin(), v.end());



  int n = 1; cin >> n;

  while(n--){
    solve();
  }
}