#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define F first;
#define S second;

int a[26];
int b[26];

void solve(){
    int n;; cin >> n;
    string s; cin >> s;
    string s2; cin >> s2;

    for(int i = 0; i < s.size(); i++){
        a[s[i]-'a']++;
    }

    for(int i = 0; i < s2.size(); i++){
        b[s2[i]-'a']++;
    }

    ll int sol = 0;
    for(int i = 0; i < 26; i++){
        sol += min(a[i], b[i]);
    }

    cout << sol << endl;

}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n = 1;
  while(n--){
    solve();
  }
}