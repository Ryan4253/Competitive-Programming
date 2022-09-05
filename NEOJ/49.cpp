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
int a[N];

int dfs(int n){
	if(v[n].empty()){
		return 1;
	}
	else if(a[n] != 0){
		return a[n];
	}
	int size = 1;
	for(int i = 0; i < v[n].size(); i++){
		size += dfs(v[n][i]);
	}
	
	a[n] = size;
	return size;
}

void solve(){
	int n, m; cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y; cin >> x >> y;
		v[x].pb(y);
	} 
	
	int r; cin >> r;
	for(int i = 0; i < r; i++){
		int box; cin >> box;
		cout << dfs(box) << endl;
	}
	
	for(int i = 0; i <= n; i++){
		v[i].clear();
	}
	memset(a, 0, sizeof(a));
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--){
		solve();
 	}
}

