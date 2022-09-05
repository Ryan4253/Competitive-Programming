#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

void solve(){
	ll int n; cin >> n;
	ll int can[n];
	ll int ora[n];
	
	for(int i = 0; i < n; i++){
		cin >> can[i];
	}
	for(int i = 0; i < n; i++){
		cin >> ora[i];
	}
	
	ll int mincan = 2147483647;
	ll int minora = 2147483647;
	
	ll int diffcan[n];
	ll int diffora[n];
	
	for(int i = 0; i < n; i++){
		mincan = min(mincan, can[i]);
		minora = min(minora, ora[i]);
	}
	
	for(int i = 0; i < n; i++){
		can[i] -= mincan;
		ora[i] -= minora;
	}
	
	ll int sol = 0;
	for(int i = 0; i < n; i++){
		sol += max(can[i], ora[i]);
	}
	
	cout << sol << endl;
	
	
	
	
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--){
		solve();
	}
}

