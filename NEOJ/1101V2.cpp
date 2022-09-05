#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

const int N = 100000+5;
vector<int> G[N];
bool visit[N];
int size[N];
int mx[N];
int sol[N];

void dfs(int now){
	visit[now] = true;
	size[now] = 1;
	mx[now] = 0;
	for(int i = 0; i < G[now].size(); i++){
		int go = G[now][i];
		if(!visit[go]){
			dfs(go);
			size[now] += size[go];
			mx[now] = max(mx[now], size[go]);
		}
	}	
	
}

void solve(){
	int n; cin >> n;
	int a, b;
	for(int i = 0; i < n-1; i++){
		cin >> a >> b;
		G[a].pb(b);
		G[b].pb(a);
	}
	dfs(0);
	int ptr = -1, min = n+10;
	for(int i = 0; i < n; i++){
		sol[i] = max(n - size[i], mx[i]);
		if(sol[i] < min){
			min = sol[i];
			ptr = i;
		}
	}
	cout << ptr << endl;
	for(int i = 0; i < n; i++){
		G[i].clear();
		visit[i] = false;
	}
	
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	for(int i = 0; i < t; i++){
		solve();
	}
}

