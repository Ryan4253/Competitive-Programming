#include<bits/stdc++.h>
using namespace std;

//#define endl '\n'
#define ll long long
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define pb push_back
#define pog ios::sync_with_stdio(0);
#define champ cin.tie(0);
#define inf 2147483647

const int N = 50 + 5;
int a[N][N];
int r, c, k, m;

int x[4] = {1, 0, -1, 0};
int y[4] = {0, 1, 0, -1};

void update(){
	int cnt[r+2][c+2];
	int pop[r+2][c+2];

	for(int i = 0; i < r+1; i++){
		for(int j = 0; j < c+1; j++){
			pop[i][j] = 0;
			cnt[i][j] = 0;
		}
	}

	for(int i = 1; i < r+1; i++){
		for(int j = 1; j < c+1; j++){
			if(a[i][j] == -1){
				continue;
			}
			for(int k = 0; k < 4; k++){
				int xx = i+x[k], yy = j+y[k];
				if(a[xx][yy] != -1){
					cnt[i][j]++;
				}
			}
			pop[i][j] = a[i][j] / k;
		}
	}

	for(int i = 1; i < r+1; i++){
		for(int j = 1; j < c+1; j++){
			for(int k = 0; k < 4; k++){
				int xx = i+x[k], yy = j+y[k];
				if(a[xx][yy] != -1){
					a[xx][yy] += pop[i][j];
				}
			}
			a[i][j] -= cnt[i][j] * pop[i][j];

		}
	}
}

void solve(){
	cin >> r >> c >> k >> m;
	for(int i = 0; i < r+2; i++){
		for(int j = 0; j < c+2; j++){
			if(i == 0 || i == r+1 || j == 0 || j == c+1){
				a[i][j] = -1;
			} 
			else{
				cin >> a[i][j];
			}
		}
	}

	for(int i = 0; i < m; i++){
		update();
	}

	int mx = -inf, mn = inf;
	for(int i = 1; i < r+1; i++){
		for(int j = 1; j < c+1; j++){
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
	pog champ
	solve();
}