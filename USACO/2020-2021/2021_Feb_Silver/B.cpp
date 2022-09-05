#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

vector<pii> cow;

void solve(){
	int n, k; cin >> n >> k;
	k--;
	cow.pb(mp(0, 0));

	for(int i = 0; i < n; i++){
		int x; cin >> x;
		if(x % 12 == 0){
			cow.pb(mp(x, x - 12));
		}
		else{
			x = x/12 + 1;
			cow.pb(mp(x*12, (x-1)*12));
		}
	}
	sort( cow.begin(), cow.end() );
	cow.erase( unique( cow.begin(), cow.end() ), cow.end() );
	reverse(cow.begin(), cow.end());

	vector<int> dist;
	for(int i = 1; i < cow.size(); i++){
		int distance = cow[i-1].S - cow[i].F;
		dist.pb(distance);
	}

	sort(dist.begin(), dist.end());

	int sol = (cow.size()-1) * 12;

	for(int i = 0; i < (int)dist.size()-k; i++){
		sol += dist[i];
	}

	cout << sol << endl;
	/*
	for(int i = 0; i < cow.size(); i++){
		cout << cow[i].F << " " << cow[i].S << endl;
	}

	for(int i = 0; i < dist.size(); i++){
		cout << dist[i] << endl;
	}
	*/


	vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};

	do{

	}while(next_permutation(v.begin(), v.end()));
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
