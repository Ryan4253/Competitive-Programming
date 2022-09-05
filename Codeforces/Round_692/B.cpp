#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

bool divis(ll int n){
	ll int ori = n;
	while(n != 0){
		ll int digit = n % 10;
		if(digit != 0){
			if(ori % digit != 0){
				return false;
			}
		}
		
		n /= 10;
	}

	return true;
}

void solve(){
	ll int n; cin >> n;
	while(!divis(n)){
		n++;
	}

	cout << n << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--){
		solve();
 	}
}
