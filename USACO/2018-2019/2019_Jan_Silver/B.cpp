#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

const int N = 1000 + 5;
int a[N][N];
int x[4] = {1, 0, -1, 0};
int y[4] = {0, 1, 0, -1};


pii bfs(int i, int j){
    int area = 1;
    int perimeter = 0;
    queue<pii> q;
    q.push(mp(i, j));
    
    while(!q.empty()){
        int xx = q.front().F, yy = q.front().S;
        a[xx][yy] = 2;
        q.pop();
        for(int i = 0; i < 4; i++){
            int newx = xx + x[i], newy = yy+y[i];
            if(a[newx][newy] == 0){
                q.push(mp(newx, newy));
                a[newx][newy] = 2;
                area++;
            }
            else if(a[newx][newy] == 1){
                perimeter++;
            }
        }    
    }
    
    return mp(area, perimeter);
}

void solve(){
	int n; cin >> n;
    string s;
    
    for(int i = 0; i < n+2; i++){
    	if(i != 0 && i != n+1){
                cin >> s;
        }

        for(int j = 0; j < n+2; j++){
            
            if(i == 0 || j == 0 || i == n+1 || j == n+1){
                a[i][j] = 1;
            }
            else{
            	if(s[j-1] == '#'){
            		a[i][j] = 0;
            	}
            	else{
            		a[i][j] = 1;
            	}
            } 
        }
    }
    
    vector<pii> sol;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(a[i][j] == 0){
                sol.pb(bfs(i, j));
            }
        }
    }
    
    int area = 0, perimeter = 1000000000;
    for(int i = 0; i < sol.size(); i++){
        if(sol[i].F > area){
            area = sol[i].F;
            perimeter = sol[i].S;
        }
        else if(sol[i].F == area){
            perimeter = min(sol[i].S, perimeter);
        }
    }
    
    cout << area << " " << perimeter << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	if(fopen("perimeter.in", "r")){
	    freopen("perimeter.in", "r", stdin);
	    freopen("perimeter.out", "w", stdout);
	}
	solve();
}