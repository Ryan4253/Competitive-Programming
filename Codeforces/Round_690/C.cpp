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
	if(n > 45){
		cout << -1 << endl;
		return;
	}

	int a[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

	vector<int> v;

	for(int i = 0; i < 9; i++){
		if(n >= a[i]){
			n -= a[i];
			v.pb(a[i]);
		}
		else{
			if(n != 0){
				v.pb(n);
			}
			break;
		}
	}

	sort(v.begin(), v.end());

	for(int i = 0; i < v.size(); i++){
		cout << v[i];
	}
	cout << endl;


}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--){
		solve();
	}
}
