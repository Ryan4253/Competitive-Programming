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
	string a, b; cin >> a >> b;
	
	int red = 0, blue = 0;

	for(int i = 0; i < n; i++){
		if(a[i] > b[i]){
			red++;
		}
		else if(b[i] > a[i]){
			blue++;
		}
	}

	if(red > blue){
		cout << "RED" << endl;
	}
	else if(blue > red){
		cout << "BLUE" << endl;
	}
	else{
		cout << "EQUAL" << endl;
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--){
		solve();
 	}
}
