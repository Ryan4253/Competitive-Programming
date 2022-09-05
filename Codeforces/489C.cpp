#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define F first;
#define S second;

string getmax(int n, int sum){
    if(n == 1 && sum == 0){
        return "0";
    }

    if(sum < 1 || 9 * n < sum){
        return "-1";
    }
    string sol = "";

    while(n != 0){
        if(sum >= 9){
            sol += "9";
            sum -= 9;
            n --;
        }
        else if(sum == 0){
            sol += "0";
            n--;
        }
        else{
            sol += (sum + '0');
            sum = 0;
            n--;
        }
    }

    return sol;
}

string getmin(int n, int sum){
    if(n == 1 && sum == 0){
        return "0";
    }

    if(sum < 1 || 9 * n < sum){
        return "-1";
    }

    string s = getmax(n, sum);
    reverse(s.begin(), s.end());

    if(s[0] == '0'){
        for(int i = 0; i < s.size(); i++){
            if(s[i] != '0'){
                s[i] = (s[i]-1);
                s[0] = '1';
                return s;
            }
        }
    }
    else{
        return s;
    }
}

void solve(){
    int n, m; cin >> n >> m;
    cout << getmin(n, m) << " " << getmax(n, m) << endl;
    
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n = 1;
  while(n--){
    solve();
  }
}