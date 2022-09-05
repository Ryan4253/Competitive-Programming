#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define F first;
#define S second;

priority_queue<int, vector<int>, greater<int>> pq;

void solve(){
    while(!pq.empty()){
        pq.pop();
    }

    ll int n; cin >> n;
    if(n == 1){
        cout << 1 << endl;
        return;
    }
    for(int i = 9; i > 1; i--){
        while(n % i == 0){
            pq.push(i);
            n /= i;
        }
    }

    if(n != 1){
        cout << -1 << endl;
        return;
    }
    else{
        while(!pq.empty()){
            cout << pq.top();
            pq.pop();
        }
    }

    cout << endl;


}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n = 1; cin >> n;
  while(n--){
    solve();
  }
}