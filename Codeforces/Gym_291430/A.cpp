#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

const int N = 100000 + 5;
vector<int> muzzle;
vector<int> normal;

void solve(){
	int n, d, m; cin >> n >> d >> m;
	int temp;
	for(int i = 0; i < n; i++){
		cin >> temp;
		if(temp > m){
			muzzle.pb(temp);
		}
		else{
			normal.pb(temp);
		}
	}
	
	sort(muzzle.begin(), muzzle.end());
	sort(normal.begin(), normal.end(), greater<int>());
	
	int sol = 0;
	
	if(!muzzle.empty()){
		sol += muzzle.back();
		muzzle.pop_back();
	}
	
	for(int i = 0; i < d * muzzle.size(); i++){
		if(!normal.empty()){
			normal.pop_back();
		}
		else{
			muzzle.erase(muzzle.begin());
		}
		
	}
	
	while(!muzzle.empty()){
		sol += muzzle.back(); 
		muzzle.pop_back();
	}
	
	while(!normal.empty()){
		sol += normal.back();
		normal.pop_back();
	}
	
	cout << sol << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n = 1;
	while(n--){
		solve();
	}
}

