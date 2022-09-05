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

void solve(){
	int aa, b; cin >> aa >> b;
	int n; cin >> n;
	int sol = 0;

	for(int i = 0; i < n; i++){
		while(true){
			int x; cin >> x;
			if(x < 0){
				a[i][-x]--;
			}
			else if(x > 0){
				a[i][x]++;
			}
			else{
				break;
			}
		}

		if(a[i][aa] > 0 && a[i][b] > 0){
			sol++;
		}
	}
	cout << sol << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
