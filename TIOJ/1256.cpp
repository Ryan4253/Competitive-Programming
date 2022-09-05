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

const int N = 100000 + 5;
vector<int> v[N];

int low[N];
int dfn[N];
int visit[N];

int ioPtr = 0;

int isCut[N];

void dfs(int now, int par){
    visit[now] = 1;
    dfn[now] = ++ioPtr;
    low[now] = dfn[now];
    int cnt = 0;
    
    for(int i = 0; i < v[now].size(); i++){
        if(!visit[v[now][i]]){
            dfs(v[now][i], now);
            cnt++;
            low[now] = min(low[now], low[v[now][i]]);
            if(dfn[now] <= low[v[now][i]]){
                isCut[now] = 1;
            }
        }
        else{
            if(dfn[v[now][i]] == par){
                
            }
            else{
                low[now] = min(low[now], dfn[v[now][i]]);
            }
        }
    }
    
    if(now == par && cnt >= 2){
        isCut[now] = 1;
    }
    else if(now == par){
        isCut[now] = 0;
    }
}

void solve(int n, int m){
	for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    
    dfs(1, 1);

    int cnt = 0;

    for(int i = 0; i <= n; i++){
    	if(isCut[i]){
    		cnt++;
    	}
    }

    if(cnt == 0){
    	cout << "0 0";

    }
    else{
    	cout << cnt << " ";
    	for(int i = 0; i <= n; i++){
        	if(isCut[i]){
       	    	cout << i << " ";
      		}
   	 	}
    }
    
    cout << endl;

    for(int i = 0; i <= n; i++){
    	isCut[i] = 0;
    	visit[i] = 0;
    	v[i].clear();
    }
    
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
    int cnt = 0;
    while(true){
    	int n, m; cin >> n >> m;
    	if(n == 0 && m == 0){
    		return 0;
    	}
        cout << "Case #" << ++cnt << ":";
        solve(n, m);
    }
}