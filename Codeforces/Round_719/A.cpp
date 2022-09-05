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

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    a[s[0]-'A'] = 1;
    for(int i = 1; i < n; i++){
        if(s[i] != s[i-1]){
            if(a[s[i]-'A'] == 1){
                cout << "NO" << endl;
                for(int i = 0; i < 26; i++){
                    a[i] = 0;
                }
                return;
            }
            else{
                a[s[i]-'A'] = 1;
            }
        }
    }

    cout << "YES" << endl;
    for(int i = 0; i < 26; i++){
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