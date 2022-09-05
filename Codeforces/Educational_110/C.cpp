#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define F first;
#define S second;

void solve(){
    string s; cin >> s;
    vector<int> v;
    int cnt = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '1'){
            if(s[i-1] != 0 && s[i-1] == '?'){
                v.pb(-cnt);
                cnt = 0;
            }
            v.pb(1);
        }
        else if(s[i] == '0'){
            if(s[i-1] != 0 && s[i-1] == '?'){
                v.pb(-cnt);
                cnt = 0;
            }
            v.pb(0);
        }
        else{
            cnt++;
        }
    }

    if(cnt != 0){
        v.pb(-cnt);
    }

    ll int sol = 0;
    ll int prevValue = -1000;
    ll int size = 0;
    vector<ll int> range;
    vector<ll int> index;
    for(int i = 0; i < v.size(); i++){
        if(prevValue == -1000){
            if(v[i] < 0){
                size += -v[i];
            }
            else{
                size++;
                prevValue = v[i];
            }
        }
        else if(prevValue != v[i]){
            if(v[i] < 0){
                size += -v[i];
                if(abs(v[i]) % 2 != 0){
                    prevValue = 1-prevValue;
                }
            }
            else{
                size++;
                prevValue = v[i];
            }
        }
        else{
            range.pb(size);
            index.pb(i-1);
            size = 1;
            prevValue = v[i];
        }
    }
    range.pb(size);
    index.pb(v.size()-1);
    
    for(int i = 1; i < index.size(); i++){
        if(v[index[i-1]] != v[index[i-1]+1]){
            if(v[index[i-1]] < 0){
                range.pb(v[index[i-1]]);
                range[i] += -v[index[i-1]];
            }
            else{
                range.pb(-1);
                range[i]++;
            }
        }
    }
    /*
    for(int i = 0; i < range.size(); i++){
        cout << range[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < index.size(); i++){
        cout << index[i] << " ";
    }
    cout << endl << endl;; 
    */
    
    
    
    
    for(int i = 0; i < range.size(); i++){
        if(range[i] < 0){
            sol -= (1ll * -range[i] * (-range[i] + 1)) / 2;
        }
        else{
            sol += (1ll * range[i] * (range[i]+1)) / 2;
        }
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