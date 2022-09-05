#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define F first;
#define S second;

int check(string s, string key){
    int index = 0;
    for(int i = 0; i < key.size(); i++){
        if(s[index] == key[i]){
            index++;
        }
    }

    return index;
}

string toString(ll int val){
    string res = "";
    while(val != 0){
        res += ((val % 10) + '0');
        val /= 10;
    }

    reverse(res.begin(), res.end());
    return res;
}

void solve(){
    string key; cin >> key;
    ll int pow = 1;
    int closestPow = 0;
    int sol = 1000000;

    for(int i = 0; i < 63; i++){
        string s = toString(pow);
        sol = min(sol, ((int)key.size()+(int)s.size() - 2 * check(s, key)));
        pow *= 2;
    }

    cout << sol << endl;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n = 1; cin >> n;
  while(n--){
    solve();
  }
}