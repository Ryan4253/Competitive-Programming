#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define F first;
#define S second;

const int N = 1000000 + 5;
int a[N];
bool visit[N];

vector<int> sol;

void dfs(int now, int dep){
    visit[now] = true;
    int go = a[now];

    if(!visit[go]){
        dfs(go, dep+1);
    }
    else{
        sol.pb(dep);
        return;
    }
}

void solve(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++){
        if(!visit[i]){
            dfs(i, 1);
        }
    }


    ll int sum = 0;
    for(int i = 0; i < sol.size(); i++){
        sum += sol[i];
    }

    cout << sum - sol.size() << endl;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n = 1;
  while(n--){
    solve();
  }
}