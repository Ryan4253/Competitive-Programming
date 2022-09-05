#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

bool check(ll int x, ll int n, ll int k, ll int m){
    ll int ret = 0;
    
    for(int i = 0; i < 100000; i++){
        ll int y = (n - ret)/x;
        if(y <= m){
            ret += (k-i)*m;
            return ret >= n;
        }
        ret += y;
    }
    
    return ret >= n;
}

void solve(){
    ll int n, k, m; cin >> n >> k >> m;
    ll int l = 1, r = 1000000000000;
    
    while(l + 1 != r){
        ll int mid = (l + r) / 2;
        if(check(mid, n, k, m)){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    
    cout << l << endl;
}

int main(){
    if(fopen("loan.in", "r")){
        freopen("loan.in", "r", stdin);
        freopen("loan.out", "w", stdout);
    }
    ios::sync_with_stdio(0); cin.tie(0);
    
    solve();
}