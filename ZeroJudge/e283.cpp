#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second


void solve(int n){
	for(int i = 0; i < n; i++){
		int a, b, c, d; cin >> a >> b >> c >> d;
		if(a == 0 && b == 1 && c == 0 && d == 1){
			cout << "A";
		}
		if(a == 0 && b == 1 && c == 1 && d == 1){
			cout << "B";
		}
		if(a == 0 && b == 0 && c == 1 && d == 0){
			cout << "C";
		}
		if(a == 1 && b == 1 && c == 0 && d == 1){
			cout << "D";
		}
		if(a == 1 && b == 0 && c == 0 && d == 0){
			cout << "E";
		}
		if(a == 1 && b == 1 && c == 0 && d == 0){
			cout << "F";
		}
	}
	cout << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	while(cin>>n){
		solve(n);
	}	
}
