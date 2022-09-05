#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long;
#define pii pair<int, int>

void solve(){
	long long int a, b, x, y, n; cin >> a >> b >> x >> y >> n;
	int aPayoff = max(a - n, x);
	int bPayoff = max(b - n, y);
	//cout << aPayoff << " " << bPayoff << endl;
	if(aPayoff > bPayoff){
		//b is better
		n -= min(n, b - y);
		b = bPayoff;
		
		//cout << n << endl;
		if(n > 0){
			a -= min(n, a - x);
		}
	}
	else{
		n -= min(n, a - x);
		a = aPayoff;
		
		//cout << n << endl;
		if(n > 0){
			b -= min(n, b - y);
		}
	}
	//cout << a << " " << b << endl;
	cout << a * b << endl;
	
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int r; cin >> r;
	while(r--){
		solve();
 	}
}

