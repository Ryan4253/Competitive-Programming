#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define F first;
#define S second;

const ll int hashValue = 181;
const ll int mod = 100000007;
const int N =500000 + 2;
ll int expo[N];
ll int preHash[N];

void build(){
    expo[0] = 1;
    for(int i = 1; i < 500000 + 2; i++){
        expo[i] = (expo[i-1] * hashValue) % mod;
    }
}

ll int Hash(string s){
    ll int ret = 0;
    for(int i = 0; i < s.size(); i++){
        ret = (ret + (s[i]) * expo[i]) % mod;
    }
    return ret;
}    

void hash2(string s){
    preHash[0] = 0;
    s = " " + s;
    for(int i = 1; i < s.size(); i++){
        preHash[i] = (preHash[i-1] + (s[i] * expo[i])) % mod;
    }
}

void solve (){
    string key; cin >> key;
    string s; cin >> s;
    build();
    ll int val = Hash(key);
    hash2(s);
    bool first = true;
    for(int i = key.size(); i <= s.size(); i++){
        if(((preHash[i] - preHash[i-key.size()]) + mod) % mod == (val * expo[i-key.size()+1]) % mod){
            if(first){
                cout << i - key.size();
                first = false;
            }
            else{
                cout << " " << i-key.size();
            }
           
        }
    }
    cout << endl;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n = 1;
  while(n--){
    solve();
  }
}