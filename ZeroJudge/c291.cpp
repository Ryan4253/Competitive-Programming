#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

const int N = 50000 + 5;
int a[N];
bool visit[N];

void dfs(int index){
	visit[index] = true;
	if(visit[a[index]] == true){
		return;
	}
	dfs(a[index]);
}

void solve(){
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int sol = 0;
	int search;
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(!visit[i]){
			dfs(i);
			cnt++;
		}
	}
	
	cout << cnt << endl;
}

int main(){
	if(fopen("gymnastics.in", "r")){
	    freopen("gymnastics.in", "r", stdin);
	    freopen("gymnastics.out", "w", stdout);
	}
	ios::sync_with_stdio(0); cin.tie(0);
	int n = 1;
	while(n--){
		solve();
 	}
}

