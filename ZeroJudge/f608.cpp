#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

const ll int inf = (1ll<<60);

const int N = 200000 + 5;
ll int a[N];
ll int tmp[N];
int dp[N];
vector<pii> v;


void DP(int n){
    tmp[0] = -1;
    for(int i = 1; i <= n+1; i++){
        tmp[i] = inf;
    }
    
    for(int i = 1; i <= n; i++){
        int pos = lower_bound(tmp, tmp + n + 1, a[i - 1]) - tmp;
        tmp[pos] = a[i-1];
    }
     
}

void solve(){
	int n; cin >> n;

    
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        v.pb(mp(x, y));
    }
    
    sort(v.begin(), v.end());
    
    for(int i = 0; i < n; i++){
        a[i] = (v[i].S)*1e9 + i;
    }
    
    DP(n);
    
    for(int i = 1; i <= n; i++){
        if(tmp[i] != inf && tmp[i+1] == inf){
        	cout << i << endl;
        	return;
        }
    }
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}