#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

int getsauce(ll int n){
	int largest = 0, smallest = 9;
	while(n){
		int r = n % 10;
		largest = max(largest, r);
		smallest = min(smallest, r);
		n /= 10;
	}
	return largest * smallest;
}

void solve(){
	ll int n, x; cin >> n >> x;
	
	for(int i = 1; i < x; i++){
		int y = getsauce(n);
		
		if(y == 0){
			cout << n << endl;
			return;
		}
		else{
			n += y;
		}
	}
	cout << n << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		solve();
	}
}

