#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(int a, int b){
    return (a % 10 == b / 10) && (a / 10 == b % 10);
}

void solve(){
    string s; cin >> s;
    int hour = (s[0]-'0') * 10 + (s[1]-'0');
    int min = (s[3]-'0') * 10 + (s[4]-'0');

    while(true){
        min++;
        if(min == 60){
            min = 0;
            hour++;
        }
        if(hour == 24){
            hour = 0;
        }

        if(isPalindrome(hour, min)){
            if(hour < 10){
                cout << "0";
            }
            cout << hour;
            cout << ":";
            if(min < 10){
                cout << "0";
            }
            cout << min << endl;
            return;
        }
    }
}

int main(){
    int n = 1; //cin >> n;
    for(int i = 0; i < n; i++){
        solve();
    }
}