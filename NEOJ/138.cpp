#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

const int N = 100000 + 5;
const int X = 1000007;
int a[N];
int b[N];

void dp(){
	a[0] = 1; a[1] = 0;
	b[0] = 0; b[1] = 1;
	
	for(int i = 2; i < N; i++){
		a[i] = (a[i-2] % X + 2 * b[i-1] % X) % X;
		b[i] = (a[i-1] % X + b[i-2] % X) % X;
	}
}


void solve(){
	int i; cin >> i;
	cout << a[i] << endl;
}

int main(){
	dp();
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		solve();
	}
}

