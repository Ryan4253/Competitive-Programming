#include<bits/stdc++.h>
using namespace std;

void solve(){
    int a, b; cin >> a >> b;
    int diag = min(abs(a), abs(b));

    int remainder = max(abs(a), abs(b)) - diag;

    if(remainder == 0){
        cout << diag * 2 << endl;
        return;
    }

    cout << diag * 2 + remainder * 2 - 1 << endl;
}

int main(){
    int n = 1; cin >> n;
    for(int i = 0; i < n; i++){
        solve();
    }
}