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
vector<int> v[N];
int a[N][2];
int visit[N][2];

void dfs(int now, int dis, int x){
    visit[now][x] = 1;
    a[now][x] = dis;
    for(int i = 0; i < v[now].size(); i++){
        if(!visit[v[now][i]][x]){
            dfs(v[now][i], dis + 1, x);
        }
    }  
}

void solve(int n){
  for(int i = 0; i < n-1; i++){
        int x, y; cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    
    dfs(0, 0, 0);
    int mx_id = 0;
    for(int i = 0; i < n; i++){
        if (a[mx_id][0] < a[i][0]){
            mx_id = i;
        }
    }
    
    dfs(mx_id, 0, 1);
    int mx = 0;
    for(int i = 0; i < n; i++){
        mx = max(mx, a[i][1]);
    }
    
    cout << mx << endl;
    
    for(int i = 0; i < n; i++){
        v[i].clear();
        visit[i][0] = 0;
        visit[i][1] = 0;
    }
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	while(cin >> n){
		solve(n);
	}
}
