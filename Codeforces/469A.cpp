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
	int a[n];
	memset(a, 0, sizeof(a));

	for(int i = 0; i < 2; i++){
		int t; cin >> t;
		for(int i = 0; i < t; i++){
			int x; cin >> x;
			a[x-1] = 1;
		}
	}

	for(int i = 0; i < n; i++){
		if(a[i] == 0){
			cout << "Oh, my keyboard!" << endl;
			return;
		}
	}

	cout << "I become the guy." << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
