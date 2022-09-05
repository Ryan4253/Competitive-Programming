#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

int p[10];
int l[10];

void solve(){
	int n; cin >> n;
	for(int i = 1; i <= n; i++){
		int x; cin >> x;
		p[x] = i;
	}

	for(int i = 1; i <= n; i++){
		cin >> l[i];
	}

	

	int lastpos = p[1];
	int sol = 0;

	for(int i = 2; i <= n; i++){
		int step = 0;
		if(p[i] <= lastpos){
			step = (lastpos-p[i])/l[p[i]]+1;
		}
		sol += step;
		lastpos = p[i]+step*l[p[i]];
	}

	cout << sol << endl;

	for(int i = 0; i < 10; i++){
		p[i] = 0;
		l[i] = 0;
	}
	
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--){
		solve();
 	}
}
