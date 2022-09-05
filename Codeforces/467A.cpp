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
	int b[n];

	for(int i = 0; i < n; i++){
		cin >> a[i] >> b[i];
	}

	int cnt = 0;

	for(int i = 0; i < n; i++){
		if(a[i] + 2 <= b[i]){
			cnt++;
		}
	}

	cout << cnt << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
