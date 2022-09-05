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

	int odd = 0;
	int even = 0;

	for(int i = 0; i < n; i++){
		if(a[i] % 2 == i % 2){
		}
		else if(i % 2 == 0){
			even++;
		}
		else{
			odd++;
		}
	}


	if(even == odd){
		cout << even << endl;
	}
	else{
		cout << -1 << endl;
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--){
		solve();
	}
}
