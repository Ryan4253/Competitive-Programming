#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second

const int N = 200000 + 5;
int a[N];



void solve(){
    int n, k, x; cin >> n >> k >> x;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a, a + n);

    vector<pii> group;

    int start = 0;
    for(int i = 0; i < n; i++){
        if(a[i] - a[i-1] > x){
            group.pb(mp(start, i-1));
            start = i;
        }
    }
    group.pb(mp(start, n-1));

    if(k == 0){
        cout << group.size() << endl;
        return;
    }

    vector<int> diff;

    for(int i = 1; i < group.size(); i++){
        diff.push_back(a[group[i].F] - a[group[i-1].S]);
    }

    for(int i = 0; i < diff.size(); i++){
        if(diff[i] % k == 0){
            diff[i] = diff[i] / k - 1;
        }
        else{
            diff[i] = diff[i] / k;
        }
    }

    int rem = 0;
    sort(diff.begin(), diff.end());

    for(int i = 0; i < diff.size(); i++){
        if( k >= diff[i]){
            k -= diff[i];
            rem++;
        }
    }

    cout << group.size() - rem << endl;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n = 1;
  while(n--){
    solve();
  }
}