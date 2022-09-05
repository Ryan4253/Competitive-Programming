#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define F first;
#define S second;

const int N = 100000 + 5;
int a[N];

void solve(){
	int n, cnt = 0, pos = 0;
	
	cin >> n >> a[0];
	for(int i = 1; i < n; i++) {
		cin >> a[i];
		if(a[i] < a[i-1])
		{
			cnt++;
			pos = i;
		}
	}
	
	if(cnt > 1 || (cnt == 1 && a[0] < a[n-1])) {
		cout << -1 << endl;
	}
	else if(cnt == 1) {
		cout << n - pos << endl;
	}
	else {
		cout << 0 << endl;
	}
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n = 1;
  while(n--){
	solve();
  }
}