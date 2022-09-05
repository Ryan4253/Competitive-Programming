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
	int a[3];
	cin >> a[0];
	cin >> a[1];
	cin >> a[2];

	sort(a, a + 3);

	cout << a[1]-a[0] + a[2]-a[1] << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
;