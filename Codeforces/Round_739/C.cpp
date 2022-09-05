#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define F first;
#define S second;

int findSquare(int n){
    int l = 0, r = 50000;
    while(l + 1 != r){
        ll int mid = (l + r) / 2;

        if(mid * mid <= n){
            l = mid;
        }
        else{
            r = mid;
        }

        if(mid * mid == n){
            return mid-1;
        }
    }

    return l;
}

void solve(){
    int n; cin >> n;
    int sq = findSquare(n);

    n -= (sq * sq+1);
    int r = 1, c = sq+1;
    r += min(n, sq);
    n -= min(n, sq);
    //cout << n << endl;
    c -= n;
    cout << r << " " << c << endl;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n = 1; cin >> n;
  while(n--){
    solve();
  }
}