#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

const int N = 20 + 5;
vector<int> v[N];

void solve(){
	int n, m; cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			int temp; cin >> temp;
			v[i].pb(temp);
		}
	}

	for(int i = 0; i < n; i++){
		sort(v[i].begin(), v[i].end(), greater<int>());
	}

	ll int sum = 0;

	for(int i = 0; i < n; i++){
		sum += v[i][0];
	}

	cout << sum << endl;
	vector<int> mod;

	for(int i = 0; i < n; i++){
		if(sum % v[i][0] == 0){
			mod.pb(v[i][0]);
		}
	}

	if(mod.empty()){
		cout << -1 << endl;
	}
	else{
		for(int i = 0; i < mod.size(); i++){
			cout << mod[i];
			if(i != mod.size()-1){
				cout << " ";
			}
		}
		cout << endl;
	}
	cout << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
