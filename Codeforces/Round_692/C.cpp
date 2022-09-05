#include<bits/stdc++.h>
using namespace std;

//#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

const int N = 200000 + 5;
vector<ll int> v[N];
vector<ll int> root[N];
bool visit[N];
ll int sol = 0;

void update(int index){
	if(v[index].size() != 0 && v[index][0] == index){
		//cout << "SELFLOOP" << endl;
		return;
	}
	else if(v[index].size() == 0){
		visit[index]=false;
		//cout << "EMPTY" << endl;
		return;
	}
	else{
		ll int side = 1;
		while(true){
			visit[index] = true;
			if(v[index].size() == 0){
				//cout << "FOUNDLINE" << endl;
				side = 1;

				while(true){
					if(root[index].size() == 0){
						visit[index] = true;
						//cout << index << endl;
						sol += side-1;
						return;
					}
					visit[index]=true;
					side++;
					//cout << index << endl;
					index = root[index][0];
				}
			}
			else if(visit[v[index][0]]){
				//cout << "FOUNDLOOP" << endl;
				sol += side + 1;
				return;
			}
			else{
				side++;
				index = v[index][0];
			}
		}

	}
}	




void solve(){
	ll int n, m; cin >> n >> m;
	for(int i = 0; i < m; i++){
		ll int x, y; cin >> x >> y;
		v[x].pb(y);
		root[y].pb(x);
	}
	
	sol = 0;

	for(int i = 1; i <= n; i++){
		if(!visit[i]){
			visit[i] = true;
			update(i);
		}
	}

	cout << sol << endl;

	for(int i = 0; i <= n; i++){
		v[i].clear();
		visit[i] = false;
		root[i].clear();
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--){
		solve();
 	}
}
