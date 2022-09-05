#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

const int N = 55;
int a[N][N];
int mov[N][N];

void update(int r, int c, int k){
	for(int i = 1; i < r + 1; i++){
		for(int j = 1; j < c + 1; j++){
			mov[i][j] = a[i][j] / k;
		}
	}

	int ii[4] = {1, 0, -1, 0};
	int jj[4] = {0, 1, 0, -1};

	for(int i = 1; i < r + 1; i++){
		for(int j = 1; j < c + 1; j++){
			int cnt = 0;
			for(int k = 0; k < 4; k++){
				int x = i + ii[k];
				int y = j + jj[k];
				if(a[x][y] != -1){
					a[x][y] += mov[i][j];
					cnt++;
				}
			}
			a[i][j] -= (cnt * mov[i][j]);
		}
	}
}

void solve(){
	int r, c, k, m; cin >> r >> c >> k >> m;
	for(int i = 0; i < r + 2; i++){
		for(int j = 0; j < c + 2; j++){
			if(i == 0 || j == 0 || i == r+1 || j == c+1){
				a[i][j] = -1;
			}
			else{
				cin >> a[i][j];
			}
		}
	}

	for(int i = 0; i < m; i++){
		update(r, c, k);
	}

	int mx = -1000000000;
	int mn = 1000000000;

	for(int i = 1; i < r + 1; i++){
		for(int j = 1; j < c + 1; j++){
			if(a[i][j] == -1){
				continue;
			}
			mx = max(mx, a[i][j]);
			mn = min(mn, a[i][j]);
		}
	}
	
	cout << mn << endl << mx << endl;

}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
