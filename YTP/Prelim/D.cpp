  #include<bits/stdc++.h>
  using namespace std;

  #define ll long long
  #define endl '\n'
  #define pb push_back
  #define pii pair<int, int>
  #define mp make_pair
  #define F first;
  #define S second;

  const int N = 500;
  int a[N];
  int b[N];

  void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < N; i++){
      a[i] = 1000000000;
    }

    for(int i = 0; i < n; i++){
      int x, t; cin >> x >> t;
      a[x] = min(a[x], t);
    }

    for(int j = 0; j <= 100; j++){
      for(int i = 1; i <= m; i++){
          b[i] = min(min(a[i], a[i-1]+1), a[i+1]+1);
      }

      for(int k = 1; k <= m; k++){
        a[k] = b[k];
      }
    }

    for(int k = 1; k <= m; k++){
      cout << a[k] << " ";
    }
    cout << endl;
  }

  int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n = 1;
    while(n--){
      solve();
    }
  }