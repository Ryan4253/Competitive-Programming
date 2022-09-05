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
	int n, x; cin >> n >> x;
	if(n <= 2){
		cout << "1" << endl;
		return;
	}
	else{
		n -= 2;
	}

	int cnt = 1;

	while(n > 0){
		cnt++;
		n -= x;
	}

	cout << cnt << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--){
		solve();
 	}
}
