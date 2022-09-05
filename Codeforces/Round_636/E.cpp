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
ll int dis[N];
ll int cost[N];
vector<pair<ll int, ll int> > v[N];

void init(){
	for(int i = 0; i < N; i++){
		dis[i] = 1e18;
	}
}

void bellmanFord(int start, int n, int m){
	init();
	dis[start] = 0;
	for(int times = 0; times < n; times++){
		for(int i = 0; i < n; i++){
			for(pii p: v[i]){
				dis[p.F] = min(dis[i] + p.S, dis[p.F]);
			}
		}
	}
}

void solve(){
	int n, m, a, b, c; cin >> n >> m >> a >> b >> c;
	a--; b--; c--;
	for(int i = 0; i < m; i++){
		cin >> cost[i];
	}

	for(int i = 0; i < m; i++){
		int x, y; cin >> x >> y;
		x--; y--;
		v[x].pb(mp(y, cost[i]));
		v[y].pb(mp(x, cost[i]));
	}

	ll int sol = 0;
	bellmanFord(a, n, m);
	sol += dis[b];
	bellmanFord(b, n, m);
	sol += dis[c];

	cout << sol << endl;

	for(int i = 0; i < N; i++){
		v[i].clear();
	}
	memset(cost, 0, sizeof(cost));
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--){
		solve();
 	}
}
