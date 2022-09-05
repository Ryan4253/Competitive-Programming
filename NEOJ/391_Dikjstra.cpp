#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<ll int, ll int>
#define F first
#define S second

const int N = 100 + 5;
ll int dis[N];
vector<pii > v[N];

void init(){
	for(int i = 0; i < N; i++){
		dis[i] = 1e18;
	}
}

void dijkstra(int start){
	init();
	dis[start] = 0;

	priority_queue<pii, vector<pii>, greater<pii> > pq;
	pq.push(mp(0, start));

	while(!pq.empty()){
		int u = pq.top().S;
		pq.pop();

		for(pii p : v[u]){
			int v = p.F;
			ll int weight = p.S;
			if(dis[v] > dis[u] + weight){
				dis[v] = dis[u] + weight;
				pq.push(mp(dis[v], v));
			}
		}
	}
}

void solve(){
	ll int n, m, s, e, f; cin >> n >> m >> s >> e >> f;
	for(int i = 0; i < m; i++){
		ll int a, b, c, d, cc; cin >> a >> b >> c >> d >> cc;
		ll int cost;
		if(f > d){
			cost = (f-d) * cc + d * c;
		}
		else{
			cost = f * c;
		}
		v[a].pb(mp(b, cost));
	}

	dijkstra(s);
	cout << dis[e] << endl;

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
