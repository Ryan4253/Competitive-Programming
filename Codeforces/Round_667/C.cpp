#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long;
#define pii pair<int, int>

void check(){
	
}


void solve(){
	int n, x, y; cin >> n >> x >> y;
	for(int i = 1; i <= y; i++){
		if((y - x) % i == 0 && x + i * (n-1) >= y){
			int cnt = 0;
			for(int j = x; j <= y; j+=i){
				cout << j << " ";
				cnt++;
			}

			int sol = x-i;
			while(sol > 0 && cnt < n){
				cout << sol << " ";
				sol -= i;
				cnt++;
			}
			
			sol = y + i;
			while(cnt < n){
				cout << sol << " ";
				sol += i;
				cnt++;
			}
			cout << endl;
			return;
		}			
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--){
		solve();
 	}
}

