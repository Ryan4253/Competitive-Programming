#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

const int N = 1000000 + 5;
ll int a[N];
ll int dpFront[N];
ll int dpBack[N];

void DP(int n){
    dpFront[0] = a[0];
    for(int i = 1; i < n; i++){
        dpFront[i] = max(dpFront[i-1], max(dpFront[i-1] + a[i], a[i]));
    }
}

void DP1(int n){
    dpBack[n-1] = a[n-1];
    for(int i = n-2; i >= 0; i--){
        dpBack[i] = max(dpBack[i+1], max(dpBack[i+1] + a[i], a[i]));
    }
}

void solve(){
	int n; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    DP(n);
    DP1(n);
    
    ll int mx = -1e17;
    for(int i = 1; i < n-1; i++){
        mx = max(mx, dpFront[i-1] + dpBack[i+1]);
    }
    
    cout << mx << endl;
    
    memset(a, 0, sizeof(a));
    memset(dpFront, 0, sizeof(dpFront));
    memset(dpBack, 0, sizeof(dpBack));
    
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    while(n--){
        solve();
    }
}