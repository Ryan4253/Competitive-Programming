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

const int N = 30000 + 6;
const int P = 16;

int lca[P][N]; // lca[i][j]: j 跳 2^i
// lca[0][1] = 1
// lca[i][j] = lca[i-1][lca[i-1][j]]

int pin[N], pout[N];
int ioPtr = 0;

vector<int> v[N];
int depth[N];

bool is_anc(int par, int son){
    return pout[par] >= pout[son] && pin[par] <= pin[son];
}

void dfs(int now, int par, int dep){
    pin[now] = ++ioPtr;
    lca[0][now] = par;
    depth[now] = dep;
    
    for(int i = 0; i < v[now].size(); i++){
        if(v[now][i] != par){
            dfs(v[now][i], now, dep+1);
        }
    }
    
    pout[now] = ++ioPtr;
}

void build(int n){
	for(int i = 1; i < P; i++){
		for(int j = 1; j <= n; j++){
			lca[i][j] = lca[i-1][lca[i-1][j]];
		}
	}
}


int query(int a, int b){
    if(is_anc(a, b)){
        return a;
    }
    else if(is_anc(b, a)){
        return b;
    }
    
    for(int i = P-1; i >= 0; i--){
        if(is_anc(lca[i][a], b)){
            ;
        }
        else{
            a = lca[i][a];
        }
    }
    
    return lca[0][a];
    
}

void solve(){
	int n, q; cin >> n >> q;
    int root = 0;
    for (int i = 1; i <= n; ++i) root ^= i;
    for(int i = 1; i <= n; i++){
        while(true){
            int c; cin >> c;
            root ^= c;
            if(c == 0){
                break;
            }
            v[i].pb(c);
        }
    }
    
    dfs(root, root, 0);
    build(n);
    
    for(int i = 0; i < q; i++){
        int a, b; cin >> a >> b;
        int lca = query(a, b);;
        cout << lca << " " << depth[a] + depth[b] - 2 * depth[lca] << endl;;
    }
    
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
