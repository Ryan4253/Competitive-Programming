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
	int tsize = 0;
	int sol = 0;
	for(int i = 1; i <= 100000; i++){
		tsize += i;
		if(n >= tsize){
			n -= tsize;
			sol++;
		}
		else{
			break;
		}
	}

	cout << sol << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
