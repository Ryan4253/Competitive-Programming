#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

const int N = 200000 + 5;
ll int a[N];
ll int b[N];

ll int gcd(ll int u, ll int v)
{
    int shift;
    if (u == 0) return v;
    if (v == 0) return u;
    shift = __builtin_ctz(u | v);
    u >>= __builtin_ctz(u);
    do {
        v >>= __builtin_ctz(v);
        if (u > v) {
            ll int t = v;
            v = u;
            u = t;
        }  
        v = v - u;
    } while (v != 0);
    return u << shift;
}

void findgcd(ll int n, ll int x){
	ll int k = a[0]+b[x];
	for(int i = 1; i < n; i++){
		k = gcd(k, a[i]+b[x]);
		if(k == 1){
			cout << 1 << " ";
			return;
		}
	}

	cout << k << " ";
}

void solve(){
	ll int n, m; cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < m; i++){
		cin >> b[i];
	}

	for(int i = 0; i < m; i++){
		findgcd(n, i);
	}
	cout << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
