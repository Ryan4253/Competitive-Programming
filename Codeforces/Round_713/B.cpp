#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

const int N = 400 + 5;
char a[N][N];

void solve(){
	int n; cin >> n;
	bool fst = true;
	pii f, s;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
			if(a[i][j] == '*'){
				if(fst){
					fst = false;
					f = mp(i, j);
				}
				else{
					s = mp(i, j);
				}
			}	

		}
	}

	
	if(f.F == s.F){ // (0, 1), (0, 2)
		if(s.F == 0){
			a[s.F+1][s.S] = '*';
			a[f.F+1][f.S] = '*';
		}
		else{
			a[s.F-1][s.S] = '*';
			a[f.F-1][f.S] = '*';
		}
	}
	else if(f.S == s.S){ // (1, 0), (2, 0);
		if(s.S == 0){
			a[s.F][s.S+1] = '*';
			a[f.F][f.S+1] = '*';
		}
		else{
			a[s.F][s.S-1] = '*';
			a[f.F][f.S-1] = '*';
		}
	}
	else{
		a[f.F][s.S] = '*';
		a[s.F][f.S] = '*';
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << a[i][j];
		}
		cout << endl;
	}

}

int main(){
		ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	while(n--){
		solve();
	}
}
