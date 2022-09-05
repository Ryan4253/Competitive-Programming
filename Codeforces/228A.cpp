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
	set<int> st;
	for(int i = 0; i < 4; i++){
		int x; cin >> x;
		st.insert(x);
	}

	cout << 4 - st.size() << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
