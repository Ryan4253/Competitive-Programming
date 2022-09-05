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
vector<int> v[N];

void solve(){
	int n; cin >> n;
    for(int i = 0; i < n-1; i++){
        int x, y; cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    
    int sol = 0;
    
    for(int i = 0; i < n; i++){
        sol = max((int)v[i].size(), sol);
    }
    
    cout << sol+1 << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
    if(fopen("planting.in", "r")){
	    freopen("planting.in", "r", stdin);
	    freopen("planting.out", "w", stdout);
	}
	solve();
}