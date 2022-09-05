#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

void solve(){
	int n, m; cin >> n >> m;
	int a[n]; 

	for(int i = 0; i < n; i++){
		cin >> a[i];
	} 
	
	sort(a+0, a+n);
	vector<int> v;
	if(a[0] != 0){
		v.pb(-a[0]);
	}
	for(int i = 0; i < n; i++){
		v.pb(a[i]);
	}
	if(a[n-1] != m){
		v.pb(2*m - a[n-1]);
	}
	
	int diff[v.size()-1], max = 0;
	for(int i = 0; i < v.size()-1; i++){
		diff[i] = v[i+1] - v[i];
		if(diff[i] > max){
			max = diff[i];
		}
	}
	
	if(max % 2 == 0){
		cout << max / 2 << ".00000000000000" << endl;
	}
	else{
		cout << max / 2 << ".50000000000000" << endl;
	}
	
	
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}

