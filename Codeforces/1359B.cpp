#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second


//void clear(int n){for(int i = 0; i < n; i++){a[i] = 0;}}

const int N = 1000 + 5;
int a[N][N];
int n, m, x, y;

int lmao(int r){
	int sum = 0;
	int cnt = 0;
	for(int i = 0; i < m; i++){
		if(a[r][i] == 1){
			if(cnt % 2 == 1){
				sum += ((cnt/2)*y)+x;
			}
			else{
				sum += ((cnt/2)*y);
			}
			cnt = 0;
		}
		else{
			cnt++;
		}
	}

	if(cnt % 2 == 1){
		sum += (cnt/2)*y+x;
	}
	else{
		sum += (cnt/2)*y;
	}

	//cout << cnt << endl;

	return sum;
}

void solve(){
	// input numbers
	cin >> n >> m >> x >> y;
	int cnt = 0; // total num of white tile
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			char temp; cin >> temp;
			if(temp == '.'){
				a[i][j] = 0;
				cnt++;
			}
			else{
				a[i][j] = 1;
			}
		}
	}

	if(2 * x <= y){
		cout << cnt * x << endl;
		return;
	}

	int sol = 0;

	for(int i = 0; i < n; i++){
		sol += lmao(i);
	}

	cout << sol << endl;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			a[i][j] = 0;
		}
	}
}

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--){
		solve();
 	}
}
