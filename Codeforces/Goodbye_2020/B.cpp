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

void solve(){
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		cnt[a[i]]++;
	}

	int sol = 0;
	for(int i = 0; i <= 2*n+5; i++){
		if(cnt[i] > 1){
				cnt[i]--;
				cnt[i+1]++;
		}
	}
	/*
	for(int i = 0; i < 10; i++){
		cout << cnt[i] << " ";
	}
	cout << endl;
	*/
	for(int i = 0; i <= 2*n+5; i++){
		if(cnt[i] != 0){
			sol++;
		}
	}

	cout << sol << endl;


	for(int i = 0; i < n; i++){
		a[i] = 0;
	}

	for(int i = 0; i <= 2 * n+5; i++){
		cnt[i] = 0;
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--){
		solve();
 	}
}
