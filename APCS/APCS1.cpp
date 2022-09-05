#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

int a1, b1, c1;
int a2, b2, c2;
int n;

int check(int i){
	int y1 = a1 * i * i + b1 * i + c1;
	int j = n - i;
	int y2 = a2 * j * j + b2 * j + c2;
	
	return y1 + y2;
}

void solve(){
	cin >> a1 >> b1 >> c1;
	cin >> a2 >> b2 >> c2;
	cin >> n;

	int sol = -2147483647;

	for(int i = 0; i <= n; i++){
		sol = max(sol, check(i));
	}

	cout << sol << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
