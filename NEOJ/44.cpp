#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

const int N = 100 + 5;
int a[N][N];
int x[4] = {0, 1, 0, -1};
int y[4] = {1, 0, -1, 0};


void bfs(pii p, int d){
	queue<pair<pii, int> > q;
	q.push(mp(p, d));
	
	while(!q.empty()){
		int xx = ((q.front()).F).F;
		int yy = ((q.front()).F).S;
		int dist = (q.front()).S;
		q.pop();
		a[xx][yy] = -1;

		for(int i = 0; i < 4; i++){
			int nx = xx + x[i];
			int ny = yy + y[i];
			if(a[nx][ny] == 0){
				a[nx][ny] = -1;
				q.push(mp(mp(nx, ny), dist+1));
			}
			else if(a[nx][ny] == 1){
				cout << dist+1 << endl;
				return;
			}
		}
	}
	cout << "= =" << "\"" << endl;
}

void solve(int n){
	pii start;
	int x;
	for(int i = 0; i < n; i++){
		string s; cin >> s;
		x = s.size();
		for(int j = 0; j < s.size(); j++){
			if(s[j] == '#'){
				a[i][j] = -1;
			}
			else if(s[j] == '.'){
				a[i][j] = 0;
			}
			else if(s[j] == '@'){
				a[i][j] = 1;
			}
			else{
				a[i][j] = -1;
				start = mp(i, j);
			}
		}
	}

	bfs(start, 0);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < x; j++){
			a[i][j] = 0;
		}
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	while(true){
		cin >> n;
		if(n != 0){
			solve(n);
		}
		else{
			return 0;
		}
	}
}
