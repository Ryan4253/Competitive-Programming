#include<bits\stdc++.h>
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
int a[N];
int visit[N];

void dfs(int now, int dis){
	a[now] = dis;
	visit[now] = 1;
	for(int i = 0; i < (int)v[now].size(); i++){
		int go = v[now][i];
		if(!visit[go]){
			dfs(go, dis+1);
		}
	}
}

void solve(){
	int n; cin >> n;
	int s, l, r; cin >> s >> l >>r;

	for(int i = 0; i < n-1; i++){
		int x, y; cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}

	dfs(s, 1);

	ll int sol = accumulate(a + l, a + l + r, 0);
	cout << sol << endl;

	for(int i = 0; i < N; i++){
		v[i].clear();
	}
	memset(a, 0, sizeof(a));
	memset(visit, 0, sizeof(visit));
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--){
		solve();
	}
}
