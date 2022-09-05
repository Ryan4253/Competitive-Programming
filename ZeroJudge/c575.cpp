#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

const int N = 50000 + 5;
int a[N];

bool check(int d, int n, int k){
	int pos = 0;
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(pos < a[i]){
			pos = a[i] + d;
			cnt++;
		}
	}

	return cnt <= k;
}

void solve(){
	int n, k; cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	sort(a, a + n);

	int l = 0, r = 1000000000 + 5;
	while(l + 1 != r){
		int mid = (l + r) / 2;
		if(check(mid, n, k)){
			r = mid;
		}
		else{
			l = mid;
		}
	}

	cout << r << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
