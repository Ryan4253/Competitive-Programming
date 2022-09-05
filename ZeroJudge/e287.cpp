#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

const int N = 100 + 5;
int a[N][N];
int visit[N][N];
int deltax[4] = {0, 1, 0, -1};
int deltay[4] = {1, 0, -1, 0};


pii move(pii loc, int n, int m){
	vector<pii> v;
	for(int i = 0; i < 4; i++){
		int x = loc.F + deltax[i];
		int y = loc.S + deltay[i];

		if(x < 0 || y < 0 || visit[x][y] || x >= n || y >= m){
			continue;
		}
		else{
			v.pb(mp(x, y));
		}
	}

	if(v.empty()){
		return mp(-1, -1);
	}

	pii bean = v[0];
	for(int i = 1; i < v.size(); i++){
		if(a[v[i].F][v[i].S] < a[bean.F][bean.S]){
			bean = v[i];
		}
	}

	return bean;
}

void solve(){
	int n, m; cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}

	pii loc = mp(0, 0);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] < a[loc.F][loc.S]){
				loc = mp(i, j);
			}
		}
	}

	ll int sol = 0;

	while(true){
		visit[loc.F][loc.S] = 1;
		sol += a[loc.F][loc.S];
		loc = move(loc, n, m);
		if(loc.F == -1){
			break;
		}
		//cout << loc.F << " " << loc.S << endl;
	}

	//cout << loc.F << " " << loc.S << endl;
	cout << sol << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
