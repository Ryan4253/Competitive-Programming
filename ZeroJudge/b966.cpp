#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second


void solve(){
	int n; cin >> n;
	vector<pii> v;
	for(int i = 0; i < n; i++){
		int l, r; cin >> l >> r;
		v.pb(mp(l, r));
	}

	sort(v.begin(), v.end());

	ll int sol = 0;
	int cl = v[0].F, cr = v[0].S;


	for(int i = 1; i < n; i++){
		int l = v[i].F, r = v[i].S;
		if(l >= cr){
			sol += cr-cl;
			cl = l; cr = r;
		}
		else if(r <= cr){

		}
		else{
			cr = r;
		}
	}

	sol += cr - cl;

	cout << sol << endl;
}


int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
