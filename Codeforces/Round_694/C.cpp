#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

const int N = 300000 + 5;
int a[N];
int cost[N];

bool coolbeans(const int &i,  const int &j){
	//return cost[a[i]-1] < cost[a[j]-1];
	return cost[i] > cost[j];
}

void solve(){
	int n, m; cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		a[i]--;
	}
	for(int i = 0; i < m; i++){
		cin >> cost[i];
	}

	sort(a, a + n, coolbeans);
	//cout <<"DONE" << endl;
	ll int sol = 0;
	int curr = 0;
	for(int i = 0; i < n; i++){
		if(curr <= a[i]){
			sol += cost[curr];
			curr++;
		}
		else{
			sol += cost[a[i]];
		}
	}

	cout << sol << endl;

	for(int i = 0; i < n; i++){
		a[i] = 0;
	}
	for(int i = 0; i < m; i++){
		cost[i] = 0;
	}
	
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--){
		solve();
 	}
}
