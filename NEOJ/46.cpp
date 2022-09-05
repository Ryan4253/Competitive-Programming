#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

const int N = 100;
int flood[105][105];

void bfs(int i, int j){
    queue< pair<int, int> > que;
    que.push(make_pair(i, j));
    int cnt;
    while(!que.empty()){
        pair <int, int> p = que.front(); que.pop();
        int i = p.first;
        int j = p.second;
        
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int newx, newy;
        for(int k = 0; k < 4; k++){
            newx = i + dx[k]; newy = j + dy[k];
            
            if(flood[newx][newy] == -2 || flood[newx][newy] == -1){
                if (flood[newx][newy] == -2) {
                    cout << flood[i][j] + 1 << endl;
                    return;
                }
                flood[newx][newy] = flood[i][j] + 1;
                que.push(make_pair(newx, newy));
            }
        }
    }
    cout << "= =\"" << endl;
}

void solve(){
    int n; cin >> n;
    if (n == 0) {
        exit(0);
    }
    int m; string s;
    for(int i = 0; i < n; i++){
        cin >> s;
        m = s.size();
        for(int j = 0; j < m; j++){
            if(s[j] == '#'){
                flood[i][j] = -3;
            }
            else if(s[j] == 'K'){
                flood[i][j] = 0;
            }
            else if(s[j] == '@'){
                flood[i][j] = -2;
            }
            else{
                flood[i][j] = -1;
            }
        } 
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(flood[i][j] == 0){
                bfs(i, j);
            }
        }
    }
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
    while(1){
        solve();
    }
}
