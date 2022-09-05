#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<ll int, ll int>
#define F first
#define S second


void solve(){
	int n, x; cin >> n >> x;
	vector<pii> v;
	for(int i = 0; i < n; i++){
		int temp; cin >> temp;
		v.pb(mp(temp, 1));
	}

	
	for(int i = 0; i < v.size(); i++){
		if(v[i].F % x != 0){
			break;
		}
		else{
			v.pb(mp(v[i].F / x, v[i].S * x));
		}
	}

	ll int sum = 0;
	for(int i = 0; i < v.size(); i++){
		sum += v[i].F * v[i].S;
	}

	cout << sum << endl;
	
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--){
		solve();
 	}
}
