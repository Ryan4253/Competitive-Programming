#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    int x; cin >> x;
    int mx = x, mn = x;

    int cnt = 0;
    for(int i = 0; i < n-1; i++){
        cin >> x;
        if(x > mx){
            cnt++;
            mx = x;
        }
        
        if(x < mn){
            cnt++;
            mn = x;
        }
    }

    cout << cnt << endl;
}

int main(){
    int n = 1; //cin >> n;
    for(int i = 0; i < n; i++){
        solve();
    }
}