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
    int n, m, k; cin >> n >> m >> k;
    if(n % 2 == 0 && m % 2 == 0){
        if(k % 2 == 0){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    else if(n % 2 == 0){
        if(k <= (n * (m-1)/2) && k % 2 == 0){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    else{
        
        k -= m/2;
        if(k < 0){
            cout << "NO" << endl;
            return;
        }
        if(k % 2 == 0){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
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