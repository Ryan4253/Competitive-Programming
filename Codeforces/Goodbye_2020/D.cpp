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
int weight[N];
vector<int> v[N];
vector<pii> pos;

void solve(){
	int n; cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> weight[i];
	}

	for(int i = 0; i < n-1; i++){
		int x, y; cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}

	ll int total = 0;
	for(int i = 1; i <= n; i++){
		total += weight[i];
	}

	for(int i = 1; i <= n; i++){
		if(v[i].size() > 1){
			pos.pb(mp(weight[i], v[i].size()-1));
		}
	}

	sort(pos.begin(), pos.end());

	cout << total << " ";
	for(int i = 0; i < n-2; i++){
		total += (pos.back()).F;
		(pos.back().S)--;
		if(pos.back().S == 0){
			pos.pop_back();
		}
		cout << total << " ";
	}
	cout << endl;

	pos.clear();
	for(int i = 0; i <= n+5; i++){
		v[i].clear();
		weight[i] = 0;
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--){
		solve();
	}
}
