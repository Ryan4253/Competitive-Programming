#include<iostream>
#include<vector>

using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

const int N = 500 + 5;
ll int dis[N];
ll int cost[N];
vector<pair<ll int, ll int> > v[N];

void init(){
	for(int i = 0; i < N; i++){
		dis[i] = 1e18;
	}
}

void bellmanFord(int start, int n){
	init();
	dis[start] = 0;

	for(int times = 0; times < n; times++){
		for(int i = 1; i <= n; i++){
			for(int j = 0; j < v[i].size(); j++){
				pair<ll int, ll int> p = v[i][j];
				dis[p.F] = min(dis[p.F], dis[i] + p.S);
			}
		}
	}
}

void solve(){
	int n; cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> cost[i];
	}

	int m; cin >> m;
	for(int i = 0; i < m; i++){
		ll int a, b, k; cin >> a >> b >> k;
		v[a].pb(mp(b, k + cost[b]));
		v[b].pb(mp(a, k + cost[a]));
	}

	bellmanFord(1, n);

	if(dis[n] == 1e18){
		cout << -1 << endl;
	}
	else{
		cout << dis[n] << endl;
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
