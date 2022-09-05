#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

void solve(){
	int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
	int n;
	if(y1 == y2){
		n = abs(x2-x1);
		cout << x1 << " " << y1 + n << " " << x2 << " " << y2 + n << endl;
	}
	else if (x1 == x2){
		int n = abs(y2-y1);
		cout << x1 + n << " " << y1 << " " << x2 + n << " " << y2 << endl;
	}
	else if (x1 != x2 && y1 != y2 && abs(x2-x1) == abs(y2-y1)){
		cout << x1 << " " << y2 << " " << x2 << " " << y1 << endl;
	}
	else{
		cout << "-1" << endl;
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}

