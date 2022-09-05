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
	int a[4];
	cin >> a[0] >> a[1] >> a[2] >> a[3];

	sort(a, a + 4);

	cout << a[3]-a[0] << " " << a[3]-a[1] << " " << a[3]-a[2] << " " << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
