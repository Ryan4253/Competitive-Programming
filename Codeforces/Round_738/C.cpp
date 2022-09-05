#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define F first;
#define S second;

const int N = 10000 + 5;
int a[N];

void clear(int n){
    for(int i = 0; i < n; i++){
        a[i] = 0;
    }
}

void solve(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    if(a[0] == 1){
        cout << n + 1 << " ";
        for(int i = 0; i < n; i++){
            cout << i+1 << " ";
        }
        cout << endl;
    }
    else if(a[n-1] == 0){ 
        for(int i = 0; i < n; i++){
            cout << i+1 << " ";
        }
        cout << n + 1 << endl;;
    }
    else{
        int loc = -1;
        for(int i = 0; i < n-1; i++){
            if(a[i] == 0 && a[i+1] == 1){
                loc = i;
            }
        }

        if(loc == -1){
            cout << -1 << endl;
            clear(n);
            return;
        }

        for(int i = 0; i <= loc; i++){
            cout << i+1 << " ";
        }
        cout << n+1 << " ";
        for(int i = loc+1; i < n; i++){
            cout << i+1 << " ";
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