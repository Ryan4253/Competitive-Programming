#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

const int N = 50;
int a[N][N];

void solve(){
	int n; cin >> n;
	int dir; cin >> dir;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
		}
	}

	int x = n/2, y = n/2;
	cout << a[x][y];

	if(dir == 0){ //left
		for(int cnt = 1; cnt < n; cnt+=2){
			for(int i = 0; i < cnt; i++){
				cout << a[x][--y];
			}
			for(int i = 0; i < cnt; i++){
				cout << a[--x][y];
			}
			for(int i = 0; i <= cnt; i++){
				cout << a[x][++y];
			}
			for(int i = 0; i <= cnt; i++){
				cout << a[++x][y];
			}
		}

		for(; y>0;){
			cout << a[x][--y];
		}
	}
	else if(dir == 1){ //up
		for(int cnt = 1; cnt < n; cnt+=2){
			for(int i = 0; i < cnt; i++){
				cout << a[--x][y];
			}
			for(int i = 0; i < cnt; i++){
				cout << a[x][++y];
			}
			for(int i = 0; i <= cnt; i++){
				cout << a[++x][y];
			}
			for(int i = 0; i <= cnt; i++){
				cout << a[x][--y];
			}
		}

		while(x>0){
			cout << a[--x][y];
		}
	}
	else if(dir == 2){ //right
		for(int cnt = 1; cnt < n; cnt+=2){
			for(int i = 0; i < cnt; i++){
				cout << a[x][++y];
			}
			for(int i = 0; i < cnt; i++){
				cout << a[++x][y];
			}
			for(int i = 0; i <= cnt; i++){
				cout << a[x][--y];
			}
			for(int i = 0; i <= cnt; i++){
				cout << a[--x][y];
			}
		}

		while(y<n-1){
			cout << a[x][++y];
		}
	}
	else{ //down
		for(int cnt = 1; cnt < n; cnt+=2){
			for(int i = 0; i < cnt; i++){
				cout << a[++x][y];
			}
			for(int i = 0; i < cnt; i++){
				cout << a[x][--y];
			}
			for(int i = 0; i <= cnt; i++){
				cout << a[--x][y];
			}
			for(int i = 0; i <= cnt; i++){
				cout << a[x][++y];
			}
		}

		while(x<n-1){
			cout << a[++x][y];
		}
	}	
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
