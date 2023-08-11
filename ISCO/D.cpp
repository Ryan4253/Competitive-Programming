#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n; string s; cin >> n >> s;
    string a;
    string b;

    bool oneDetected = false;
    
    for(auto c : s){
        if(c == '2'){
            if(oneDetected){
                a += '0';
                b += '2';
            }
            else{
                a += '1';
                b += '1';
            }

        }
        else if(c == '0'){
            a += '0';
            b += '0';
        }
        else{
            if(!oneDetected){
                a += '1';
                b += '0';
                oneDetected = true;
            }
            else{
                a += '0';
                b += '1';
            }
        }
    }

    cout << a << '\n' << b << '\n';
}

int main(){
    int n = 1; cin >> n;
    for(int i = 0; i < n; i++){
        solve();
    }
}