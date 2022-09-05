#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long;
#define pii pair<int, int>


void solve(){
	int a, b; cin >> a >> b;
	int diff = max(a, b) - min(a, b);
	
	if(diff % 10 == 0){
		cout << diff / 10 << endl;
	}
	else{
		cout << diff / 10 + 1 << endl;
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--){
		solve();
 	}
}

