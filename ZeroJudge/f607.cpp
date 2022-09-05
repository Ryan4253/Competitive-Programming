#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

const int N = 200000 + 5;
set<int> st;
int a[N];

void solve(){
	int n, l; cin >> n >> l;
	st.insert(0); st.insert(l);
	ll int sol = 0;

	for(int i = 0; i < n; i++){
		int x, y; cin >> x >> y;
		a[y-1] = x;
	}

	for(int i = 0; i < n; i++){
		int top = *st.upper_bound(a[i]);
		int bottom = *prev(st.upper_bound(a[i]));
		sol += top - bottom;
		st.insert(a[i]);
	}

	cout << sol << endl;

}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
