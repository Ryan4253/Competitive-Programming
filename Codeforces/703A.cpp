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
	int m = 0, c = 0;

	for(int i = 0; i < n; i++){
		int x, y; cin >> x >> y;
		if(x > y){
			m++;
		}
		else if(y > x){
			c++;
		}
	}

	if(m == c){
		cout << "Friendship is magic!^^" << endl;
	}
	else if(m > c){
		cout << "Mishka" << endl;
	}
	else{
		cout << "Chris" << endl;
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
