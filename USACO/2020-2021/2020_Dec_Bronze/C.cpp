#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int, int>
#define pll pair<ll int, ll int>
#define pb push_back
#define mp make_pair
#define F first
#define S second

const int N = 50 + 5;
int dir[N]; // 0 = north, 1 = east
vector<pll> coord;
pll endloc[N];


void update(int index, int n){
	ll int sol = 1e18;

	if(dir[index]==0){
		for(int i = 0; i < n; i++){
			if(dir[i]!=1){
				continue;
			}
			ll int deltax = coord[index].F - coord[i].F;
			ll int deltay = coord[i].S - coord[index].S;

			if(deltax > 0 && deltay > 0 && deltax < deltay && (endloc[i].F>coord[index].F || endloc[i].F==-1)){
				sol = min(sol, deltay);
			}
			
		}
		if(sol == 1e18){
			endloc[index].F = -1;
			endloc[index].S = -1;
		}
		else{
			endloc[index].F = coord[index].F;
			endloc[index].S = coord[index].S+sol;
		}
	}
	else{
		for(int i = 0; i < n; i++){
			if(dir[i]!=0){
				continue;
			}
			ll int deltax = coord[i].F - coord[index].F;
			ll int deltay = coord[index].S - coord[i].S;

			//cout << deltax << " " << deltay << endl;

			if(deltax > 0 && deltay > 0 && deltay < deltax && (endloc[i].S>coord[index].S || endloc[i].F == -1)){
				sol = min(sol, deltax);
			}
		}
		if(sol == 1e18){
			endloc[index].F = -1;
			endloc[index].S = -1;
		}
		else{
			endloc[index].F = coord[index].F+sol;
			endloc[index].S = coord[index].S;
		}
	}
}

void solve(){
	int n; cin >> n;

	for(int i = 0; i < n; i++){
		string c; cin >> c;
		int x, y; cin >> x >> y;

		if(c == "N"){
			dir[i] = 0;
			coord.pb(mp(x, y));
		}
		else{
			dir[i] = 1;
			coord.pb(mp(x, y));
		}
	}

	for(int i = 0; i < N; i++){
		endloc[i] = mp(100000000000, 100000000000);
	}

	
	for(int times = 0; times < 100; times++){
		for(int i = 0; i < n; i++){
			update(i, n);
		}
	}


	for(int i = 0; i < n; i++){
		if(endloc[i].F==-1){
			cout << "Infinity" << endl;
		}
		else{
			cout << max(endloc[i].F-coord[i].F, endloc[i].S-coord[i].S) << endl;
		}
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}