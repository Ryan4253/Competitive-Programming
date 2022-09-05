#include<iostream>
#include<algorithm>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

void solve(){
	int n; cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	} 
	sort(a, a + n);
	cout << a[n-2] << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}

