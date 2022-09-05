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
int a[N];
vector<pii> v[N];
/*
int mindist(int start, int end){
    //queue<i
    
    while(!que.empty()){
        pii wasdwasd = que.top();
        que.pop();
    }
}
*/

void solve(){
	int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    
    for(int i = 0; i < m; i++){
        int a, b, cost; cin >> a >> b >> cost;
        v[a].pb(mp(b, cost));
        v[b].pb(mp(a, cost));
    }
    
    vector<pii> mov;
    
    for(int i = 1; i <= n; i++){
        if(a[i] != i){
            mov.pb(mp(a[i], i));
        }
    }
    
    if(mov.empty()){
        cout << -1 << endl;
        return;
    }
    int sol = 9;
    for(int i = 0; i < mov.size(); i++){
        //sol = min(sol, mindist(mov[i].S, mov[i].F));
    }   
    
    cout << sol << endl;
    
    
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
    if(fopen("wormsort.in", "r")){
        freopen("wormsort.in", "r", stdin);
        freopen("wormsort.out", "w", stdout);
    }
	solve();
}