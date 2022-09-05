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
	int a, b, c; cin >> a >> b >> c;
	a = min(a, 1); b = min(b, 1);
	int aand = a & b; int oor = a | b; int xxor = a ^ b;

	bool flag = true;

	if(aand == c){
		cout << "AND" << endl;
		flag = false;
	}
	if(oor == c){
		cout << "OR" << endl;
		flag = false;
	}
	if(xxor == c){
		cout << "XOR" << endl;
		flag = false;
	}

	if(flag){
		cout << "IMPOSSIBLE" << endl;
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
