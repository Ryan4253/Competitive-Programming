#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

void solve(){
	int n; cin >> n;
	int x, y;
	if(n <= 21){
		y = 0;
		x = (n - 1) * 5;
	}
	else if(n <=41){
		x = 100;
		y = (n - 21) * 5;
	}
	else if(n <= 61){
		y = 100;
		x = 100 - (n - 41) * 5;
	}
	else{
		x = 0;
		y = 100-(n-61) * 5;
	}
	
	cout << "(" << x << "," << y << ")" << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
 
