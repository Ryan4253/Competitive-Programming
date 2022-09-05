#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

bool check(int n){
	int a[11];
	memset(a, 0, sizeof(a));
	while(n != 0){
		int rem = n % 10;
		if(a[rem] == 1){
			return false;
		}
		a[rem] = 1;
		n /= 10;
	}

	return true;

}

void solve(){
	int n; cin >> n;
	n++;
	while(!check(n)){
		n++;
	}
	cout << n << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
