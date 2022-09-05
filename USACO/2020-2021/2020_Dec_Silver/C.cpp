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

const int N = 1000 + 5;

pll coord[N];
pll endcoord[N];
int dir[N]; // 0 = north, 1 = south

vector<int> v[N];
bool visit[N];

ll int dp[N];

void update(int index, int n){
	ll int dist = 1e18;
	if(dir[index] == 0){
		for(int i = 0; i < n; i++){
			if(dir[i] == 0){
				continue;
			}

			ll int deltax = coord[index].F - coord[i].F;
			ll int deltay = coord[i].S - coord[index].S;

			if(deltax > 0 && deltay > 0 && deltax < deltay){
				dist = min(dist, deltay);
			}
		}

		if(dist == 1e18){
			endcoord[index]=mp(-1, -1);
		}
		else{
			endcoord[index]=mp(coord[index].F, coord[index].S+dist);
		}
	}
	else{
		for(int i = 0; i < n; i++){
			if(dir[i] == 1){
				continue;
			}

			ll int deltax = coord[i].F - coord[index].F;
			ll int deltay = coord[index].S - coord[i].S;

			if(deltax > 0 && deltay > 0 && deltay < deltax){
				dist = min(dist, deltax);
			}
		}

		if(dist == 1e18){
			endcoord[index]=mp(-1, -1);
		}
		else{
			endcoord[index]=mp(coord[index].F+dist, coord[index].S);
		}
		
	}
	
}

void build(int index, int n){
	ll int dist = 1e18;
	ll int ii = -1;

	if(dir[index] == 0){
		for(int i = 0; i < n; i++){
			if(dir[i] == 0){
				continue;
			}

			ll int deltax = coord[index].F - coord[i].F;
			ll int deltay = coord[i].S - coord[index].S;

			if(deltax > 0 && deltay > 0 && deltax < deltay && (endcoord[i].F>coord[index].F || endcoord[i].F==-1)){
				if(deltay < dist){
					dist = deltay;
					ii = i;
				}
			}
		}
	}
	else{
		for(int i = 0; i < n; i++){
			if(dir[i] == 1){
				continue;
			}

			ll int deltax = coord[i].F - coord[index].F;
			ll int deltay = coord[index].S - coord[i].S;

			if(deltax > 0 && deltay > 0 && deltay < deltax && (endcoord[i].S>coord[index].S || endcoord[i].F == -1)){
				if(deltax < dist){
					dist = deltax;
					ii = i;
				}
			}
		}
	}

	if(ii == -1){
	}
	else{
		v[ii].pb(index);
	}
}

int dfs(int now){
	if(v[now].size() == 0){
		dp[now] = 0;
		return 1;
	}
	else if(dp[now] != -1){
		return dp[now];
	}

	ll int size = 1;

	for(int i = 0; i < (int)v[now].size(); i++){
		
		size += dfs(v[now][i]);
	}
	
	dp[now] = size;
	return size;
}





void solve(){
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		char s; cin >> s;
		dir[i] = (s != 'N');

		ll int x, y; cin >> x >> y;
		coord[i] = mp(x, y);
	}

	for(int i = 0; i < n; i++){
		update(i, n);
	}
	
	for(int i = 0; i < n; i++){
		build(i, n);
	}

	for(int i = 0; i < n; i++){
		dp[i] = -1;
	}
	
	for(int i = 0; i < n; i++){
		dfs(i);
	}

	for(int i = 0; i < n; i++){
		if(dp[i] != 0){
			cout << dp[i]-1 << endl;
		}
		else{
			cout << dp[i] << endl;
		}
	}

	
	

}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
