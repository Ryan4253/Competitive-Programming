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
int a[N];
int pre[N];

void solve(){
	int n, m; cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(i == 0){
			pre[i] = a[i];
		}
		else{
			pre[i] = pre[i-1]+a[i];
		}
	}

	ll int msum = 0;
	ll int psum = pre[n-1];

	for(int i = 0; i < m; i++){
		int temp; cin >> temp;
		msum += temp;
	}

	msum %= psum;

	for(int i = 0; i < n; i++){
		if(msum <= pre[i]){
			cout << (i+1)%n << endl;
			return;
		}
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
