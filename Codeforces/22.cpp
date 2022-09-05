#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

const int N = 1000000 + 5;
int a[N];
vector<ll int> v;

int index(int target){
	int l = 0;
	int r = v.size()-1;

	while(l + 1 != r){
		int mid = (l + r) / 2;
		if(v[mid] == target){
			r = mid;
		}
		else{
			l = mid;
		}
	}

	return l;
}

void solve(){
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	ll int sol = 0;
	v.pb(1e18);

	for(int i = 0; i < n; i++){
		while(v.back() < a[i]){
			sol ++;
			v.pop_back();
		}

		v.pb(a[i]);

		int r = index(a[i]);
		if(r == 0){
			sol += v.size()-2;
		}
		else{
			sol += v.size()-r-1;
		}

	}

	cout << sol << endl;
	memset(a, 0, sizeof(a));
	v.clear();
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--){
		solve();
 	}
}
