#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

const int N = 300000 + 5;
int color[N];
vector<int> v[N];
int bluecnt[N];
int redcnt[N];
int visit[N];
int sol = 0;
int allred = 0;
int allblue = 0;

void dfs(int now){    
    if(color[now] == 1){
        redcnt[now] ++;
    }
    else if(color[now] == 2){
        bluecnt[now]++;
    }
    
    visit[now] = 1;
    
    for(int i = 0; i < v[now].size(); i++){
        if(visit[v[now][i]] == 0){
            dfs(v[now][i]);
            bluecnt[now] += bluecnt[v[now][i]];
            redcnt[now] += redcnt[v[now][i]];
            
            if(bluecnt[v[now][i]] == allblue && redcnt[v[now][i]] == 0){
                sol++;
            }
            else if(redcnt[v[now][i]] == allred && bluecnt[v[now][i]] == 0){
                sol++;
            }
        }
    } 
}

void solve(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> color[i];
        if(color[i] == 1){
            allred++;
        }
        else if(color[i] == 2){
            allblue++;
        }
    }
    int x, y;
    for(int i = 0; i < n-1; i++){
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    
    dfs(1);
    
    cout << sol << endl;
    
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
    solve();
}
