#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int, int>
#define pll pair<ll int, ll int>
#define pb push_back
#define mp make_pair
#define F first
#define S second

void solve(){
	int n; cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	ll int sol = 0;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i > j){
				continue;
			}

			ll int sum = 0;
			ll int cnt = 0;

			for(int k = i; k <= j; k++){
				cnt++;
				sum += a[k];
			}

			double avg = (double)sum / cnt;

			for(int k = i; k <= j; k++){
				if(avg == (double)a[k]){
					sol++;
					break;
				}
				
			}
		}
	}

	cout << sol << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}