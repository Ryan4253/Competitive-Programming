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
int a[N];
vector<pii> range;

void solve(){
	int n, k; cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	range.pb(mp(a[0], a[0]+k-1));
	
	for(int i = 1; i < n-1; i++){
		range.pb( mp(a[i], a[i]+2*(k-1)));
	}
	range.pb(mp(a[n-1], a[n-1]+k-1));
	/*
	for(int i = 0; i < n; i++){
		cout << range[i].F << " " << range[i].S << endl;
	}
	*/
	for(int i = 0; i < n-1; i++){
		if(range[i].S < range[i+1].F || range[i].F > range[i+1].S){
			cout << "NO" << endl;
			for(int i = 0; i < n; i++){
				a[i] = 0;
				range[i]=mp(0, 0);
			}
			return;
		}
		else{
			if(range[i+1].S >= range[i].S){
				range[i+1]=mp(range[i+1].F, range[i].S+k-1);
			}
			else{
				range[i+1]=mp(range[i].F-k+1, range[i+1].S);
			}
		}

	}

	cout << "YES" << endl;
	for(int i = 0; i < n; i++){
		a[i] = 0;
	}
	range.clear();
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--){
		solve();
 	}
}
