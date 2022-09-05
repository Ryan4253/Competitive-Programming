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
int cnt[N];
ll int perm2[N];
ll int perm3[N];

void init(){
	for(int i = 3; i < N; i++){
		perm3[i] = 1ll * i * (i-1) * (i-2) / 6;
	}
	for(int i = 2; i < N; i++){
		perm2[i] = 1ll * i * (i-1) / 2;
	}
}

void solve(){
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	for(int i = 0; i < n; i++){
		cnt[a[i]]++;
	}

	ll int sol = 0;

	for(int i = 1; i <= n; i++){
		sol += perm3[cnt[i]];
	}

	for(int i = 1; i <= n-1; i++){
		sol += (perm2[cnt[i]]*cnt[i+1] + perm2[cnt[i+1]]*cnt[i]);
	}

	for(int i = 1; i <= n-2; i++){
		sol += (perm2[cnt[i]]*cnt[i+2] + perm2[cnt[i+2]]*cnt[i]);

	}

	for(int i = 1; i <= n-2; i++){
		sol += ((cnt[i] * cnt[i+1] * cnt[i+2]));
	}

	cout << sol << endl;	
	for(int i = 0; i <= n; i++){
		a[i] = 0;
		cnt[i] = 0;
	}

}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	init();
	int n; cin >> n;
	while(n--){
		solve();
 	}


}
