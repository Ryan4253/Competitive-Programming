#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define F first;
#define S second;

int y = 0, t = 0, p = 0;

void calc(string s){
  for(int i = 0; i < s.size(); i++){
    if(s[i] == 'Y' || s[i] == 'y'){
      y++;
    }
    if(s[i] == 'T' || s[i] == 't'){
      t++;
    }
    if(s[i] == 'P' || s[i] == 'p'){
      p++;
    }

  }
}

void solve(){
  vector<string> s;
  string temp;
  while(cin>>temp){
    s.pb(temp);
  }

  for(int i = 0; i < s.size(); i++){
    calc(s[i]);
  }

  cout << min(min(y, t), p) << endl;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n = 1;
  while(n--){
    solve();
  }
}