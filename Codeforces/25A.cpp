#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

void solve(){
	int n; cin >> n;
	int a[n];
	for(int i =0 ; i < n; i++){
		cin >> a[i];
	}
	
	int even = 0, odd = 0;
	for(int i = 0; i < n; i++){
		if(a[i] % 2 == 0){
			even++;
		}
		else{
			odd++;
		}
	}
	
	if(odd == 1){
		for(int i = 0; i < n; i++){
			if(a[i] % 2 == 1){
				cout << i + 1 << endl;
				return;
			}
		}
	}
	else{
		for(int i = 0; i < n; i++){
			if(a[i] % 2 == 0){
				cout << i + 1 << endl;
				return;
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}

