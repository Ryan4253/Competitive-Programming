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

const int N = 1000 + 5;
vector<int> v[N];
int in[N];
queue<int> q;
vector<int> sol;

void solve(){
	int n, k; cin >> n >> k;
    for(int i = 0; i < k; i++){
        int a, b; cin >> a >> b;
        v[a].pb(b);
        in[b]++;
    }
    
    for(int i = 1; i <= n; i++){
        if(in[i] == 0){
            q.push(i);            
        }
    }
    
    while(q.size() != 0){
        int f = q.front();
        sol.pb(f);
        q.pop();
        for(int i = 0; i < v[f].size(); i++){
            in[v[f][i]]--;
            if(in[v[f][i]] == 0){
                q.push(v[f][i]);
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        if(in[i] != 0){
            cout << "NO" << endl;
            return;
        }
    }
    
    cout << "YES" << endl;
    
    for(int i = 0; i < sol.size(); i++){
        cout << sol[i] << endl;
    }
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}