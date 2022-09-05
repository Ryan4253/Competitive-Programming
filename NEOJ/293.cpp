#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

const int N = 10000+5;
vector<int> G[N];
bool visit[N];
int rip;
int sol[N];

void dfs(int now, int &count){
	visit[now] = true;
	count++;
	
	for(int i = 0; i < G[now].size(); i++){
		int go = G[now][i];
		if(!visit[go] && go != rip){
			dfs(go, count);
		}
	}
}

void solve(){
	int n; cin >> n;
	int a, b;
	int max = 0;
	for(int i = 0; i < n-1; i++){
		cin >> a >> b;
		G[a].pb(b);
		G[b].pb(a);
	}
	
	for(int i = 0; i < n; i++){
		rip = i;
		for(int j = 0; j < n; j++){
			if(j != rip && !visit[j]){
				int count = 0;
				dfs(j, count);
				if(count >= max){
					max = count;
				}
			}
		}
		sol[i] = max;
		max = 0;
		for(int j = 0; j < n; j++){
			visit[j] = false;
		}
	}
	int ptr = -1, min = n+100;
	for(int i = 0; i < n; i++){
		if(sol[i] < min){
			min = sol[i];
			ptr = i;
		}
	}
	cout << ptr << endl;
	for(int i = 0; i < n; i++){
		G[i].clear();
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	for(int i = 0; i < t; i++){
		solve();
	}
}

