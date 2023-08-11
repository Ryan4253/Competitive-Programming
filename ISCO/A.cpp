#include<bits/stdc++.h>
using namespace std;

bool isLower(char c){
    return c >= 'a' && c <= 'z';
}

void solve(){
    string s; cin >> s;
    int lower = 0;
    for(auto c : s){
        if(isLower(c)){
            lower++;
        }
    }

    for(int i = 0; i < s.size(); i++){
        
        if(lower >= (s.size()+1)/2){
            if(!isLower(s[i])){
                s[i] = s[i] - 'A' + 'a';
            }
        }
        else{
            if(isLower(s[i])){
                s[i] = s[i] - 'a' + 'A';
            }
        }
    }
    cout << s << endl;
}

int main(){
    int n = 1; //cin >> n;
    for(int i = 0; i < n; i++){
        solve();
    }
}
