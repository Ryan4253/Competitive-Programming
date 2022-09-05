#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define F first;
#define S second;

const int N = 200000 + 5;
int a[N];
vector<pii> rem;

void solve(){
    int n, k; cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i] = ((k-(a[i] % k))%k);
    }
    /*
    for(int i = 0; i < n; i++){
      cout << a[i] << " ";
    }
    cout << endl;
    */
    sort(a, a + n);
    int startloc = n-1;
    for(int i = 0; i < n; i++){
      if(a[i] != 0){
        startloc = i;
        break;
      }
    }
    int mxindex = startloc;
    int mxcnt = 1;
    int currcnt = 1;

    for(int i = startloc+1; i < n; i++){
      if(a[i] == a[i-1]){
        currcnt++;
      }
      else{
        if(currcnt >= mxcnt){
          mxcnt = currcnt;
          mxindex = i-1;
          currcnt = 1;
        }
        else{
          currcnt = 1;
        }
      }
    }

    if(currcnt >= mxcnt){
      mxcnt = currcnt;
      mxindex = n-1;
    }
    else{
      currcnt = 1;
    }
    /*
    for(int i = 0; i < n; i++){
      cout << a[i] << " ";
    }
    cout << endl;

    cout << mxcnt << " " << mxindex << endl;
    */

    if(a[mxindex] != 0){
      cout << 1ll * (mxcnt - 1) * k + a[mxindex]+1 << endl;
    }
    else{
      cout << 0 << endl;
    }
    
    
    for(int i = 0; i < n; i++){
      a[i] = 0;
    }

}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n = 1; cin >> n;
  while(n--){
    solve();
  }
}