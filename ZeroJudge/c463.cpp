#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second
#define BRUH ios::sync_with_stdio(0); cin.tie(0);

const int N = 100000 + 5;
vector<int> child[N];
int isChild[N];
int depth[N];


ll int dfs(int now){
	if(child[now].empty()){
		depth[now]=0;
		return 0;
	}
	
	ll int mxdep = 0;

	for(int i = 0; i < (int)child[now].size(); i++){
		int go = child[now][i];
		mxdep = max(dfs(go), mxdep);
	}

	depth[now] = mxdep+1;
	return mxdep+1;
}

void solve(){
	int n; cin >> n;
	for(int i = 1; i <= n; i++){
		int m; cin >> m;
		for(int j = 0; j < m; j++){
			int x; cin >> x;
			child[i].pb(x);
			isChild[x]=1;
		}
	}

	int root = 0;
	for(int i = 1; i <= n; i++){
		if(!isChild[i]){
			root = i;
			break;
		}
	}

	ll int sum = 0;

	cout << root << endl;
	dfs(root);
	for(int i = 1; i <= n; i++){
		sum += depth[i];
	}
	cout << sum << endl;
}

int main(){
	solve();
}

