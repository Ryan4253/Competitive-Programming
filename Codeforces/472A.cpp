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
	if(n % 2 == 0){
		cout << 4 << " " << n-4 << endl;
	}
	else{
		cout << 9 << " " << n-9 << endl;
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
