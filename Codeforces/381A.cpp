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
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	int lptr = 0;
	int rptr = n-1;
	int player[] = {0, 0};
	for(int i = 0; i < n; i++){
		if(a[lptr] > a[rptr]){
			player[i%2] += a[lptr];
			lptr++;
		}
		else{
			player[i%2] += a[rptr];
			rptr--;
		}
	}

	cout << player[0] << " " << player[1] << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
