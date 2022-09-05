#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

const int N = 100000 + 5;
int a[2 * N];
int ind[N];
bool visit[N];

void solve(){
	int n; cin >> n;
	for(int i = 0; i < 2 * n; i++){
		cin >> a[i];
	}

	for(int i = 0; i < 2 * n; i++){
		if(!visit[(a[i])]){
			visit[(a[i])] = true;
			ind[(a[i])] = i;
		}
	}

	int sol = 0;

	for(int i = 1; i <= n; i++){
		int cnt = 0;

		for(int j = ind[i] + 1; j < 2 * n; j++){
			if(a[j] == i){
				break;
			}
			else if(a[j] < i){
				cnt++;
			}
		}
		sol += cnt;
	}

	cout << sol << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
