#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

const int N = 100000 + 5;
int w[N];
int f[N];
int a[N];

bool coolbeans(int a, int b){
	return w[a] * f[b] < w[b] * f[a];
}

void solve(){
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		a[i] = i;
		cin >> w[i];
	}
	for(int i = 0; i < n; i++){
		cin >> f[i];

	}

	sort(a, a + n, coolbeans);

	ll int sol = 0;
	ll int weight = 0;
	for(int i = 0; i < n; i++){
		sol += weight * f[a[i]];
		weight += w[a[i]];
	}

	cout << sol << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
