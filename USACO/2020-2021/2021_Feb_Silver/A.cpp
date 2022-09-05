#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

const int N = 2021;
int a[N][N];
int sol = 0;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
queue<pii> q;

void put(int x, int y, bool flag){
    a[x][y] = 1;
    q.push(mp(x, y));
    sol += flag;
    for(int i = 0; i < 4; i++){
        int xx = x + dx[i], yy = y + dy[i];
        if(a[xx][yy] == 1){
            q.push(mp(xx, yy));
        }
    }
}

void bfs(){
    while(!q.empty()){
        pii curr = q.front();
        int x = curr.F, y = curr.S;
        q.pop();
        
        int sidesum = a[x-1][y] + a[x+1][y] + a[x][y+1] + a[x][y-1];
        
        if(sidesum == 3){
            for(int i = 0; i < 4; i++){
                int xx = x + dx[i], yy = y + dy[i];
                if(a[xx][yy] == 0){
                    put(xx, yy, 1);
                    break;
                }
            }
        }
    }
}

void solve(){
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		int x, y; cin >> x >> y;
		x += 503; y += 503;
		if(a[x][y] == 1){
			sol--;
		}
		else{
            put(x, y, 0);
            bfs();
		}
		cout << sol << endl;
	}
    
    
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}