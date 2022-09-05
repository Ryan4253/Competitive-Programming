#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

const int N = 100 + 5;
int a[N];
int b[N];

int amx_sum(int size){
	int sol = -1000, tempmax = 0;

	for(int i = 0; i < size; i++){
		tempmax += a[i];
		sol = max(sol, tempmax);
	}

	return max(sol, 0);
}

int bmx_sum(int size){
	int sol = -1000, tempmax = 0;

	for(int i = 0; i < size; i++){
		tempmax += b[i];
		sol = max(sol, tempmax);
	}

	return max(sol, 0);
}

void solve(){
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int m; cin >> m;
	for(int i = 0; i < m; i++){
		cin >> b[i];
	}

	cout << max(0, amx_sum(n) + bmx_sum(m)) << endl;

	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));

}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--){
		solve();
 	}
}
