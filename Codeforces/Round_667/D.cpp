#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long;
#define pii pair<int, int>


void solve(){
	unsigned long long int n, m; cin >> n >> m;
	unsigned long long int original = n;
	vector<unsigned long long int> v;
	while(n != 0){
		v.pb(n % 10);
		n /= 10;
	}
	
	for(int i = 0; i < v.size(); i++){
		if(accumulate(v.begin(), v.end(), 0) <= m){
			break;
		}
		else{
			v[i] = 0;
			if(i == v.size() - 1){
				v.pb(1);
			}
			else{
				v[i + 1]++;
			}
		}
		for(int i = 0; i < n; i++){
			if(v[i] == 10){
				v[i] = 0;
				v[i+1]++;
			}
		}
	}
	reverse(v.begin(), v.end());
	unsigned long long int sol = 0;
	
	for(int i = 0; i < v.size(); i++){
		sol += v[i];
		sol *= 10;
	}
	sol /= 10;
	cout << sol - original << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--){
		solve();
 	}
}

