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
    string s; cin >> s;
    int a[s.size()];
    int first = 2147483647, final = 0;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == '?'){
            a[i] = -1;
        }
        else if(s[i] == 'B'){
            a[i] = 0;
            first = min(first, i);
            final = max(final, i);
        }
        else{
            a[i] = 1;
            first = min(first, i);
            final = max(final, i);
        }
    }

    if(first == 2147483647){
        a[0] = 1;
        for(int i = 1; i < s.size(); i++){
            a[i] = 1-a[i-1];
        }
    }
    else{
        for(int i = first-1; i >= 0; i--){
            a[i] = 1-a[i+1];
        }
    
        for(int i = final+1; i < s.size(); i++){
            a[i] = 1-a[i-1];
        }

        for(int i = first; i < final; i++){
            if(a[i] == -1){
                a[i] = 1-a[i-1];
            }
        }
    }



    
    for(int i = 0; i < s.size(); i++){
        if(a[i] == 0){
            cout << "B";
        }
        else{
          cout << "R";
        }
    }
    cout << endl;
    
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n = 1; cin >> n;
  while(n--){
    solve();
  }
}