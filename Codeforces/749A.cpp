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

		cout << n/2 << endl;
	
		for(int i = 0; i < n/2-1; i++){
			cout << 2 << " ";
		}
	if(n % 2 == 1){
		cout << 3 << endl;
	}
	else{
		cout << 2 << endl;
	}

}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
