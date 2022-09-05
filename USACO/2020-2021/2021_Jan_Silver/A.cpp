#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define F first
#define S second

const int N = 100000 + 5;
int a[N];
vector<int> v[N];
vector<int> graph[N];
bool visit[N];

vector<int> member;
vector<int> pos;
bool visited[N];

int sol[N];

void dfs(int now){
	visit[now] = true;
	member.pb(now);

	for(int i = 0; i < v[now].size(); i++){
		int vis = v[now][i];
		if(!visited[vis]){
			pos.pb(vis);
			visited[vis] = true;
		}
	}

	for(int i = 0; i < graph[now].size(); i++){
		int go = graph[now][i];
		if(!visit[go]){
			dfs(go);
		}
	}
}

void solve(){
	int n, k; cin >> n >> k;
	for(int i = 1; i <= n; i++){
		a[i] = i;
		v[i].pb(i);
	}

	for(int i = 0; i < k; i++){
		int x, y; cin >> x >> y;
		v[a[x]].pb(y);
		v[a[y]].pb(x);
		swap(a[x], a[y]);
		
	}

	for(int i = 1; i <= n; i++){
		graph[i].pb(a[i]);
	}

	for(int i = 1; i <= n; i++){
		if(!visit[i]){
			dfs(i);
			for(int i = 0; i < member.size(); i++){
				sol[member[i]] = pos.size();
			}

			for(int i = 0; i < pos.size(); i++){
				visited[pos[i]] = false;
			}

			member.clear();
			pos.clear();
		}
	}

	for(int i = 1; i <= n; i++){
		cout << sol[i] << endl;
	}


}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}