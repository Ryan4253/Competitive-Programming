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
    int n; cin >> n;
    vector<int> odd;
    vector<int> even;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x % 2 == 0){
            even.pb(x);
        }
        else{
            odd.pb(x);
        }
    }

    sort(odd.begin(), odd.end(), greater<int>());
    sort(even.begin(), even.end(), greater<int>());
    vector<int> v;
    v.insert(v.end(), even.begin(), even.end());
    v.insert(v.end(), odd.begin(), odd.end());
    int sol = 0;
    for(int i = 0; i < v.size(); i++){
        for(int j = i; j < v.size(); j++){
            if(i == j){
                continue;
            }
            else{
                if(__gcd(v[i], 2 * v[j]) != 1){
                    sol++;
                }
            }
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