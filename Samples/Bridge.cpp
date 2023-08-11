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

const int N = 200000 + 5;
vector<int> G[N];

int e[N], x[N], y[N];
int dfn[N];
int low[N];
int isBridge[N];
int visit[N];

int ptr = 0;

void addEdge(int a, int b, int i){
    G[a].pb(i);
    G[b].pb(i);
    x[i] = a;
    y[i] = b;
    e[i] = a ^ b;
}

void dfs(int now, int par){
    visit[now] = true;
    dfn[now] = ++ptr;
    low[now] = dfn[now];
    
    for (int eid: G[now]) {
        int to = (e[eid] ^ now);
        if(!visit[to]){
            dfs(to, now);
            if (low[to] <= dfn[now]){
                low[now] = low[to];
            }
            else{
                isBridge[to] = true;
            }       
        }
        else if (to != par) {
            low[now] = min(low[now], dfn[to]);
        }
    }
}



void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        addEdge(x, y, i);
    }
    
    dfs(1, 1);

    bool flag = false;
    
    for(int i = 0; i < n; i++){
        int cnt = 0;
        for(int j = 0; j < G[i].size(); j++){
            cnt += !isBridge[G[i][j]];
        }
        
        if(cnt >= 4){
        	flag = true;
            cout << i << " ";
        }
    }

    if(!flag){
    	cout << "None" << endl;
    }
    
    cout << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}