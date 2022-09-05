#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define pb push_back
#define pog ios::sync_with_stdio(0);
#define champ cin.tie(0);
#define inf 2147483647

int a1, b1, c1;
int a2, b2, c2;
int n;

int value(int i){
	int v1 = a1 * i * i + b1 * i + c1;
	int v2 = a2 * (n-i) * (n-i) + b2 * (n-i) + c2;

	return v1 + v2;
}

void solve(){
	cin >> a1 >> b1 >> c1;
	cin >> a2 >> b2 >> c2;
	cin >> n;

	int sol = -inf;
	for(int i = 0; i <= n; i++){
		sol = max(sol, value(i));
	}

	cout << sol << endl;
}

int main(){
	pog champ
	solve();
}