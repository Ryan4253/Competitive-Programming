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
	int a[n];

	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	int pos[1000];
	memset(pos, 0, sizeof(pos));
	int sol = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(a[i] == a[j]){
				continue;;
			}
			else{
				if(pos[abs(a[i]-a[j])] == 0){
					pos[abs(a[i]-a[j])] = 1;
					sol++;
				}
			}
		}
	}

	cout << sol << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--){
		solve();
 	}
}
