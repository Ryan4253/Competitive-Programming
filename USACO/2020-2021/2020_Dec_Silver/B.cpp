#include<bits/stdc++.h>
using namespace std;

//#define endl '\n'
#define ll long long
#define pii pair<int, int>
#define pll pair<ll int, ll int>
#define pb push_back
#define mp make_pair
#define F first
#define S second

const int N = 2500 + 5;
pll coord[N];

string convert(int n, int sz){
	string sol = "";
	while(n != 0){
		sol += ('0'+n%2);
		n /= 2;
	}

	while(sol.size() < sz){
		sol += '0';
	}

	reverse(sol.begin(), sol.end());
	return sol ;
}

void solve(){
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		int x, y; cin >> x >> y;
		coord[i] = mp(x, y);
	}

	
	int sol = 0;

	for(int i = 0; i < pow(2, n); i++){
		vector<pii> v;
		string bit = convert(i, n);
		bool flag = true;
		v.clear();
		
		for(int i = 0; i < n; i++){
			//cout << "HI" << endl;
			
			
			if(bit[i] == '1'){
				v.pb(coord[i]);
			}
		}

		int minx = 1e9, miny = 1e9, maxx = 0, maxy = 0;
		for(int i = 0; i < (int)v.size(); i++){
			maxx = max(maxx, v[i].F);
			minx = min(minx, v[i].F);
			maxy = max(maxy, v[i].S);
			miny = min(miny,v[i].S);
		}
		
		for(int i = 0; i < n; i++){
			if(coord[i].F >= minx && coord[i].F <= maxx && coord[i].S >= miny && coord[i].S <= maxy && bit[i] == '0'){
				flag = false;
			}
		}
		

		if(flag){
			sol++;
		}
		
	}
	cout << sol << endl;
}	




int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
