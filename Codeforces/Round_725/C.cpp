#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define F first;
#define S second;

const int N = 200000 + 5;
vector<int> v;

void solve(){
    int n, l, r; cin >> n >> l >> r;
    for(int i = 0; i < n; i++){
        int temp; cin >> temp;
        v.pb(temp);
    }

    sort(v.begin(), v.end());
    ll int sol = 0;
    vector<int>::iterator lower, upper;

    for (auto it = begin (v); it != end (v); ++it) {
        //cout << it-v.begin()+1 << endl;
        lower = lower_bound(v.begin(), it, l-v[it-v.begin()]);
        upper = upper_bound(v.begin(), it, r-v[it-v.begin()]);
        sol += (upper-lower);
        //cout << upper-v.begin()+1 << endl;
        //cout << lower-v.begin() +1<< endl;
    }

    //lower = lower_bound(v.begin(), v.end(), l-v[v.size()-1]);
    //upper = upper_bound(v.begin(), v.end(), r-v[v.size()-1]);
    //sol += (upper-lower);

    cout << sol << endl;




    v.clear();

}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n = 1; cin >> n;
  while(n--){
    solve();
  }
}