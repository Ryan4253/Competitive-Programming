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

const int N = 500 + 5;
int v[N][N];

vector<int> sol;

void dfs(int now){
    bool flag = true;
    for(int i = 0; i < N; i++){
        if (v[now][i]) {
            --v[now][i];
            --v[i][now];
            dfs(i);;
            flag = false;
        }
    }
    
    sol.pb(now);
}

void solve(){
	int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        v[x][y]++;
        v[y][x]++;
    }
    
    int start = 1000;
    for(int i = 0; i < N; i++){
        int cnt = 0;
        for(int j = 0; j < N; j++){
            if(v[i][j]){
                cnt+= v[i][j];
            }
        }
        
        if(cnt % 2 == 1){
            start = i;
            break;
        }
        else if(cnt > 0){
            start = min(start, i);
        }
    }
    
    dfs(start);
    
    reverse(sol.begin(), sol.end());
    
    for(int i = 0; i < sol.size(); i++){
        cout << sol[i] << endl;
    }
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}