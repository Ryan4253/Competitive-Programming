#include<bits/stdc++.h>
using namespace std;

//#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second
#define int ll


//void clear(int n){for(int i = 0; i < n; i++){a[i] = 0;}}

struct edge{
	int a, b, cost;
	edge(int aa, int bb, int ccost){
		a = aa, b = bb, cost = ccost;
	}
};

bool cmp(edge first, edge second){
	if(first.cost >= second.cost){
		return false;
	}
	return true;
}

vector<edge> sides;
const int N = 100000 + 5;

struct disjoint_set{
	int p[N];
	void initialize(){
		for(int i = 0; i < N; i++){
			p[i] = i;
		}
	}

	int find(int a){
		if(p[a] == a){
			return a;
		}
		else{
			return p[a] = find(p[a]);
		}
	}

	void uni(int a, int b){
		p[find(a)] = find(b);
	}
};

vector<edge> tree;
vector<edge> nonTree;

vector<pii> v[N];

const int P = 18;
int lca[P][N];
int maxDist[P][N];
int pin[N], pout[N];
int pPtr = 0;
int depth[N];

int minSpanWeight = 0;

bool isAnc(int a, int b){
	return pin[b] >= pin[a] && pout[a] >= pout[b];
}



void dfs(int now, int par, int parLen, int dep){
	lca[0][now] = par;
	maxDist[0][now] = parLen;
	pin[now] = ++pPtr;
	depth[now] = dep;
	for(int i = 0; i < v[now].size(); i++){
		if(v[now][i].F != par){
			dfs(v[now][i].F, now, v[now][i].S, dep+1);
		}
	}

	pout[now] = ++pPtr;
}

int calcMaxDist(int a, int b){
	int dep = depth[a] - depth[b];
	int sol = 0;

	for(int i = P-1; i >= 0; i--){
		if(dep >= (1<<i)){
			dep -= (1<<i);
			sol = max(sol, maxDist[i][a]);
			a = lca[i][a];
		}
	}

	return sol;

}

int calculate(int a, int b){
	int originalA = a;
	int ancestor;
	if(isAnc(a, b)){
		ancestor = a;
	}
	else if(isAnc(b, a)){
		ancestor = b;
	}	
	else{
		for(int i = P-1; i >= 0; i--){
			if(isAnc(lca[i][a], b)){

			}
			else{
				a = lca[i][a];
			}
		}

		ancestor = lca[0][a];
	}

	return max(calcMaxDist(originalA, ancestor), calcMaxDist(b, ancestor));




}

void solve(){
	int n, m; cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a, b, cost; cin >> a >> b >> cost;
		sides.pb({a-1, b-1, cost});
	}

	sort(sides.begin(), sides.end(), cmp);
	disjoint_set st;
	st.initialize();

	for(int i = 0; i < sides.size(); i++){
		if(st.find(sides[i].a) != st.find(sides[i].b)){
			st.uni(sides[i].a, sides[i].b);
			tree.pb(sides[i]);
			minSpanWeight += sides[i].cost;
		}
		else{
			nonTree.pb(sides[i]);
		}
	}

	for(int i = 0 ; i < tree.size(); i++){
		v[tree[i].a].pb(mp(tree[i].b, tree[i].cost));
		v[tree[i].b].pb(mp(tree[i].a, tree[i].cost));
	}

	dfs(0, 0, 0, 0);
	for(int i = 1; i < P; i++){
		for(int j = 0; j < n; j++){
			lca[i][j] = lca[i-1][lca[i-1][j]];
			maxDist[i][j] = max(maxDist[i-1][lca[i-1][j]], maxDist[i-1][j]);
		}
	}

	int sol = 2147483647;

	for(int i = 0; i < nonTree.size(); i++){
		int candidate = minSpanWeight + nonTree[i].cost;
		candidate -= calculate(nonTree[i].a, nonTree[i].b);
		sol = min(sol, candidate);
	}

	cout << minSpanWeight << " " << sol << endl;

	for(int i = 0; i < n; i++){
		v[i].clear();
		depth[i] = 0;
	}
	sides.clear();
	tree.clear();
	nonTree.clear();
	minSpanWeight = 0;
}

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--){
		solve();
 	}
}
