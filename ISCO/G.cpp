#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s; cin >> s;
    int n = 0;
    bool flag = false;
    for(auto c : s){
        if(c == '1' && !flag){
            flag = true;
        }
        if(flag && c == '0'){
            n++;
        }
    }

    if(n >= 6){
        cout << "yes" << endl;
    }
    else{
        cout << "no" << endl;
    }
}

int main(){
    int n = 1; //cin >> n;
    for(int i = 0; i < n; i++){
        solve();
    }
}