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
priority_queue<int, vector<int>, greater<int> > pq;
int deg[N];
vector<int> v[N];
vector<int> sol;

void solve(){
	int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        deg[b]++;
        v[a].pb(b);
    }
    
    for(int i = 0; i < n; i++){
        if(deg[i] == 0){
            pq.push(i);
        }
    }
    
    while(!pq.empty()){
        int p = pq.top();
        pq.pop();
        sol.pb(p);
        for(int i = 0; i < v[p].size(); i++){
            deg[v[p][i]]--;
            if(deg[v[p][i]] == 0){
                pq.push(v[p][i]);
            }
        }
    }
    
    if(sol.size() == n){
        for(int i = 0; i < sol.size(); i++){
            cout << sol[i];
            if(i != sol.size()-1){
            	cout << " ";
            }
        }
        cout << endl;
    }
    else{
        cout << "QAQ" << endl;
    }
    
    
    for(int i = 0; i < N; i++){
    	v[i].clear();
    }
    sol.clear();
    memset(deg, 0, sizeof(deg));
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
    while(n--){
        solve();
    }
}