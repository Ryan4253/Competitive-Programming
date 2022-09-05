#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

const int N = 100000 + 5;
vector<pii> v;
vector<pii> sol;

bool cmp(pii a, pii b){
    if(a.F == b.F){
        return a.S > b.S;
    }
    else{
        return a.F < b.F;
    }
}

void solve(){
	int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        v.pb(mp(x-y, x+y));
    }
    
    sort(v.begin(), v.end(), cmp);
    
    sol.pb(v[0]);
    for(int i = 1; i < n; i++){
        pii end = sol.back();
        if(v[i].S > end.S){
            sol.pb(v[i]);
        }
    }
    
    cout << sol.size() << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
    if(fopen("mountains.in", "r")){
	    freopen("mountains.in", "r", stdin);
	    freopen("mountains.out", "w", stdout);
	}
	solve();
}