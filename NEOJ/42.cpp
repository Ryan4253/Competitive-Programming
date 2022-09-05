#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

const int N = 1000 + 5;
int a[N][N];
int x[4] = {0, 1, 0, -1};
int y[4] = {1, 0, -1, 0};

void bfs(pii p){
	queue<pii> q;
	q.push(p);

	while(!q.empty()){
		int xx = q.front().F;
		int yy = q.front().S;
		a[xx][yy] = 1;
		q.pop();

		for(int i = 0; i < 4; i++){
			int nx = xx + x[i];
			int ny = yy + y[i];

			if(a[nx][ny] == 0){
				a[nx][ny] = 1;
				q.push(mp(nx, ny));
			}
		}
	}
}

void solve(){
	int n, m; cin >> n >> m;
	string s; 
	for(int i = 0; i < n+2; i++){
		if(i != 0 && i != n+1){
			cin >> s;
		}
		
		for(int j = 0; j < m+2; j++){
			if(i == 0 || j == 0 || i == n+1 || j == m+1){
				a[i][j] = 2;
			}
			else{
				if(s[j-1] == '#'){
					a[i][j] = 1;
				}
				else{
					a[i][j] = 0;
				}
				
			}
		}
	}

	int cnt = 0;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(a[i][j] == 0){
				cnt++;
				bfs(mp(i, j));
			}
		}
	}

	cout << cnt << endl;

	for(int i = 0; i < n+2; i++){
		for(int j = 0; j < m+2; j++){
			a[i][j] = 0;
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
