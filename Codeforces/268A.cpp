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
	int n; cin >> n;
	int home[n];
	int guest[n];

	for(int i = 0; i < n; i++){
		cin >> home[i] >> guest[i];
	}

	int sol = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i == j){
				continue;
			}

			if(home[i] == guest[j]){
				sol++;
			}
		}
	}

	cout << sol << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
