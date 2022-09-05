#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

void solve(){
	int n, x; cin >> n >> x;
	vector<int> v;
	while(x != 0){
		v.pb(x % 10);
		x /= 10;
	}
	
	int value = 0;
	int base = 0;
	
	for(int i = 0; i < v.size(); i++){
		base += v[i] * pow(n, i);
		value += pow(v[i], v.size());
	}
	
	if (base == value){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}

