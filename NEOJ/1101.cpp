#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

const int N = 100000+5;
vector<int> G[N];
bool Vis[N];
int color[N];
bool solution = true;

void dfs(int now, int clr){
	Vis[now] = true;
	color[now] = clr;
	for(int i = 0; i < G[now].size(); i++){
		int to = G[now][i];
		if(!Vis[to]){
			dfs(to, 1-clr);
		}
		else{
			if(color[now] == color[to]){
				solution = false;
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int a, b, n, m;
	
	while(cin >> n){
		if(n == 0){
			break;
		}
		cin >> m;
		for(int i = 0; i < m; i++){
			cin >> a >> b;
			G[a].pb(b);
			G[b].pb(a);	
		}
		for(int i = 0; i < n; i++){
			color[i] = 2;
		}
		for(int i = 0; i < n; i++){
			if(!Vis[i]){
				dfs(i, 0);
			}	
		}
		if(solution == true){
			cout << "NORMAL." << endl;
		}
		else{
			cout << "RAINBOW." << endl;
		}
		solution = true;
		for(int i = 0; i < n; i++){
			Vis[i] = 0;
			G[i].clear();
		}
		
	}
}

