#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

const int N = 100 + 2;
vector<pair<ll int, ll int> > v[N];
ll int dis[N];

void init(){
    for(int i = 0; i < N; i++){
        dis[i] = 1e18;
    }
}

void bellmanFord(int start, int n, int m){
    init();
    dis[start] = 0;
    //n = vertex, m = edge
    for (int times = 0; times < n; ++times) {
        for (int i = 0; i < n; ++i) {
            for (pair<ll int, ll int> p: v[i]) {
                // visit all edges
                dis[p.F] = min(dis[i] + p.S, dis[p.F]);
            }
        }
    }
}

void solve(){
    ll int n, m, s, e, f; cin >> n >> m >> s >> e >> f;
    //n = city, m = edges, s = start, e = end, f = cargo count
    
    for(int i = 0; i < m; i++){
        ll int a, b, c, d, e; cin >> a >> b >> c >> d >> e;
        //a = start, b = end, c = cost, d = over d box, e = reduced price
        ll int cost;
        if(f > d){
            cost = 1ll * c * d + 1ll * (f - d) * e;
        }
        else{
            cost = 1ll * f * c;
        }
        v[a-1].pb(mp(b-1, cost));
    }
    
    bellmanFord(s-1, n, m);
    
    cout << dis[e-1] << endl;

    for(int i = 0; i < N; i++){
    	v[i].clear();
    }
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--){
		solve();
 	}
}