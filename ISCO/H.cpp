#include<bits/stdc++.h>
using namespace std;

const int N = 100000 + 5;
int a[N];

#define endl '\n'

void solve(){
    int n, x; cin >> n >> x;
    bool flag = true;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i] %= x;
        if(a[i] != 0){
            flag = false;
        }
    }

    if(flag){
        cout << "-1" << endl;
        return;
    }

    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += a[i];
    }

    if(sum % x != 0){
        cout << n << endl;
        return;
    }

    int lc = 0, rc = 0;

    for(int i = 0; i < n; i++){
        lc++;
        if(a[i] != 0){
            break;
        }
    }

    for(int i = n-1; i >= 0; i--){
        rc++;
        if(a[i] != 0){
            break;
        }
    }

    cout << max(n-lc, n-rc) << endl;
}

int main(){
    int n = 1; cin >> n;
    for(int i = 0; i < n; i++){
        solve();
    }
}