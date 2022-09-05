#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

void solve(){
	int n, d, m; cin >> n >> d >> m;
	int temp;
	vector<int> ban;
	vector<int> safe;
	for(int i = 0; i < n; i++){
		cin >> temp;
		if(temp > m){
			ban.pb(temp);
		}
		else{
			safe.pb(temp);
		}
	}
	
	sort(ban.begin(), ban.end(), greater<int>());
	sort(safe.begin(), safe.end(), greater<int>());
	
	int total = 0;
	if(m % (d + 1) != 0){
		total += ban.back();
		ban.pop_back();
	}


	while(!ban.empty()){
		total += ban.back();
		for(int i = 0; i < d; i++){
			if(!safe.empty()){
				safe.pop_back();
			}
			else{
				ban.erase(ban.end());
			}
		}
		ban.pop_back();
	} 
	
	while(!safe.empty()){
		total += safe[0];
		safe.pop_back();
	}
	cout << total << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}

