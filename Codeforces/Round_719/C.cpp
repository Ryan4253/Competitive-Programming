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
  if(n == 2){
      cout << -1 << endl;
      return;
  }

  int a[n][n];

  vector<pii> start;
  pii vert = {0, 0};
  pii hor = {0, n-1};

  for(int i = 0; i < 2 * n - 1; i++){
      if(i % 2 == 0){
          start.pb(vert);
          vert.first++;
      }
      else{
          start.pb(hor);
          hor.second--;
      }
  }

  pii curPos = start[0];
  int startVal = 1;
  for(int i = 1; i <= n * n; i++){
      a[curPos.first][curPos.second] = i;
      curPos.first++; curPos.second++;
      if(curPos.first >= n || curPos.second >= n){
          curPos = start[startVal];
          startVal++;
      }
  }

  for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
          cout << a[i][j] << " ";
      }
      cout << endl;
  }


}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n = 1; cin >> n;
  while(n--){
    solve();
  }
}