#include<bits/stdc++.h>
using namespace std;

//  #define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second
#define inf 2147483647

const int N = 1000 + 5;
vector<int> v[N];
bool visit[N];
string DNA[N];
int root;
ll int dp[N][4]; // 0 = A, 1 = U, 2 = C, 3 = G

int convert(char s){
    if(s == 'A'){
        return 0;
    }
    else if(s == 'U'){
        return 1;
    }
    else if(s == 'C'){
        return 2;
    }
    else if(s == 'G'){
        return 3;
    }
    else{
        return 4;
    }
}

void dfs(int now, int m){
    //cout << "HI" << endl;
    visit[now] = true;
    int letter = convert(DNA[now][m]);
    for(int i = 0; i < 4; i++){
        dp[now][i] = inf;
    }
    
    
    if(letter != 4){
        dp[now][letter] = 0;
        for(int i = 0; i < v[now].size(); i++){
            int go = v[now][i];
            if(!visit[go]){
                dfs(go, m);
                int temp = inf;
                for(int j = 0; j < 4; j++){
                    temp = min(1ll*temp, dp[go][j] + (letter != j));
                }
                dp[now][letter] += temp;
            }
        }
    }
    else{
        for(letter = 0; letter < 4; letter++){
            dp[now][letter] = 0;
        }
        for(int i = 0; i < v[now].size(); i++){
            int go = v[now][i];
            if(!visit[go]){
                dfs(go, m);
                for (int letter = 0; letter < 4; ++letter) {
                    //cout << "LMAO" << endl;
                    int temp = inf;
                    for(int j = 0; j < 4; j++){
                        temp = min(1ll*temp, dp[go][j] + (letter != j));
                    }
                    dp[now][letter] += temp;
                }
            }
        }
        
    }
    
    //cout << now << ": " << dp[now][0] << " " << dp[now][1] << " " << dp[now][2] << " " << dp[now][3] << endl;
}

ll int update(int m){
    dfs(root, m);
    return min({dp[root][0], dp[root][1], dp[root][2], dp[root][3]});
}

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        string s; cin >> s;
        if(x == y){
            root = x;
        }
        else{
            v[x].pb(y);
            v[y].pb(x);
        }
        
        DNA[x] = s;
    }   
    
    ll int sol = 0;
    for(int i = 0; i < m; i++){
        //cout << "BRUH" << endl;
        sol += update(i);
        for(int i = 0; i < n; i++){
            visit[i] = false;
        }
    }
    
    
    
    cout << sol << endl;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}