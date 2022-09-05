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
	ll int a[n];

	for(int i = 0;i < n; i++){
		cin >> a[i];
	}

	for(int times = 0; times < 5; times++){
		for(int i = 0; i < n; i++){
			ll int update = 1;
			for(int j = 0; j < n; j++){
				if(fmod(sqrt(a[i] * a[j]), 1) == 0){
					update *= a[j];
				}
			}
			a[i] *= update;
		}

		for(int i = 0; i < n; i++){
			cout << a[i] << " ";
		}
		cout << endl;
	}
	
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
