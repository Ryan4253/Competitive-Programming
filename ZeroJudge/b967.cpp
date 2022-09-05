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
vector<int> v[N];
int dist[N][2];
bool visit[N][2];


void dfs(int now, int dis, int time){
	visit[now][time] = true;
	dist[now][time] = dis;

	for(int i = 0; i < v[now].size(); i++){
		int go = v[now][i];
		if(!visit[go][time]){
			dfs(go, dis+1, time);
		}
	}

}



void solve(int n){
	for(int i = 0; i < n-1; i++){
		int x, y; cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}

	dfs(0, 0, 0);

	int pos = 0;
	
	for(int i = 0; i < n; i++){
		if(dist[pos][0] < dist[i][0]){
			pos = i;
		}
	}
	dfs(pos, 0, 1);

	int sol = 0;
	for(int i = 0; i < n; i++){
		sol = max(sol, dist[i][1]);
	}

	cout << sol << endl;

	for(int i = 0; i < n; i++){
		v[i].clear();
		visit[i][0] = false;
		visit[i][1] = false;
		dist[i][0] = 0;
		dist[i][1] = 0;
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	while(cin >> n){
		solve(n);
 	}
}
