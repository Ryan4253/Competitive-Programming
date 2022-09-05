#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

int calcCost(vector<int> v){
	vector<int> aa;
	for(int i = 0; i < v.size(); i++){
		aa.pb(v[i]);
	}

	sort(aa.begin(), aa.end());
	int sol = 0;
	for(int i = 0; i < v.size()-1; i++){
		for(int j = i; j < v.size(); j++){
			if(v[j] == aa[i]){
				sol += (j-i+1);
				for(int k = i; k <= (j+i)/2; k++){
					swap(v[k], v[j-k+i]);
				}
				break;
			}
		}
	}
	return sol;
}

void solve(){
	int n, c; cin >> n >> c;
	vector<int> v;
	for(int i = 1; i <= n; i++){
		v.pb(i);
	}

	do{
		if(calcCost(v) == c){
			for(int i = 0; i < n; i++){
				cout << v[i] << " ";
			}
			cout << endl;
			return;
		}
	}while(next_permutation(v.begin(), v.end()));

	cout << "IMPOSSIBLE" << endl;


}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for(int i = 1; i <= n; i++){
		cout << "Case #" << i << ": ";
		solve();
	}	
}
