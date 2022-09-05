#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

const int N = 10 + 5;
int a[N][N];
int opr[N];
int r, c;

void rotate(){
	int temp[r][c];
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			temp[i][j] = a[i][j];
		}
	}	

	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			a[c-j-1][i] = temp[i][j];
		}
	}

	int tmp = r;
	r = c;
	c = tmp;

}

void flip(){
	int temp[r][c];
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			temp[i][j] = a[i][j];
		}
	}

	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			a[i][j] = temp[r-i-1][j];
		}
	}
}

void solve(){
	int m; cin >> m;
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			cin >> a[i][j];
		}
	}

	for(int i = 0; i < m; i++){
		cin >> opr[i];
	}

	reverse(opr, opr + m);
	for(int i = 0; i < m; i++){
		if(opr[i] == 0){
			rotate();
		}
		else{
			flip();
		}
	}
	
	cout << r << " " << c << endl;
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			cout << a[i][j];
			if(j != c-1){
				cout << " ";
			}
		}
		cout << endl;
	}

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			a[i][j] = 0;
		}
		opr[i] = 0;
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	while(cin >> r && cin >> c){
		solve();
	}
}
