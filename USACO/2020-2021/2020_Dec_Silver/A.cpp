#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define pii pair<int, int>
#define pll pair<ll int, ll int>
#define pb push_back
#define mp make_pair
#define F first
#define S second

const int N = 100000 + 5;
bool power[N];
vector<int> v[N];
vector<int> v1[N];
bool visit[N];
ll int sol = 0;


void init(){
	for(int i = 2; i < 100005; i*=2){
		power[i]=true;
	}
}

void dfs(int now){
	int child = v[now].size();
	if(child == 0){
		return;
	}

	sol += child;
	sol += log(child+1) / log(2);

	if(!power[child+1]){
		sol++;
	}

	for(int i = 0; i < (int)v[now].size(); i++){
		int go = v[now][i];
		dfs(go);
	}
}

void build(int now){
	visit[now] = true;
	for(int i = 0; i < (int)v1[now].size(); i++){
		int go = v1[now][i];

		if(!visit[go]){
			v[now].pb(go);
			build(go);
		}
	}

}

void solve(){
	init();
	int n; cin >> n;
	for(int i = 0; i < n-1; i++){
		int x, y; cin >> x >> y;
		v1[x].pb(y);
		v1[y].pb(x);
	}
	
	build(1);
	dfs(1);

	cout << sol << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
