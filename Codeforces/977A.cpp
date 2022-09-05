#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long;
#define pii paid<int, int>


void solve(){
	int n, x; cin >> x >> n;
	for(int i = 0; i < n; i++){
		if(x % 10 == 0){
			x /= 10;
		}
		else{
			x--;
		}
	}
	cout << x << endl;
	
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n =1;
	while(n--){
		solve();
 	}
}

