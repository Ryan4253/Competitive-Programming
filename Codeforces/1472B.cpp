#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

int cnt[2];

void solve(){
	int n; cin >> n;

	for(int i = 0; i < n; i++){
		int x; cin >> x;
		if(x == 1){
			cnt[0]++;
		}
		else{
			cnt[1]++;
		}
	}

	cnt[1] %= 2;


	if(cnt[1] == 1 && cnt[0] >= 2){
		cnt[0] -= 2;
		cnt[1] = 0;
	}

	cnt[0] %= 2;

	if(cnt[1] == 0 && cnt[0] == 0){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}

	cnt[0] = 0; cnt[1] = 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--){
		solve();
	}
}
