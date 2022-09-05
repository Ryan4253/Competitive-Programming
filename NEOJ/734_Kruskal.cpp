#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

const int N = 200000 + 5;

struct disjoint_set{
	int p[N];
	void init(){
		for(int i = 0; i < N; i++){
			p[i] = i;
		}
	}

	int find(int x){
		return p[x] == x ? x : p[x] = find(p[x]);
	}

	void uni(int x, int y){
		p[find(x)] = find(y);
	}
};

vector<pair<int, pair<int, int> > > v;

ll int Kruskal(){
	disjoint_set st;
	st.init();

	sort(v.begin(), v.end());
	ll int weight = 0;

	for(int i = 0; i < (int)v.size(); i++){
		int x = (v[i].S).F;
		int y = (v[i].S).S;
		if(st.find(x) == st.find(y)){
			continue;
		}
		else{
			weight += v[i].F;
			st.uni(x, y);
		}
	}

	return weight;
}

void solve(){
	int n, m; cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a, b, cost; cin >> a >> b >> cost;
		v.pb(mp(cost, mp(a, b)));
	}

	cout << Kruskal() << endl;

}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
