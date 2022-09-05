#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

const int N = 500000 + 5;
int a[N];
int sparse[N][20];
int lg[N];

void init(){
    lg[1] = 0;
    for(int i = 2; i < N; i++){
        lg[i] = lg[i/2]+1;
    }
}



void solve(){
    init();
    
	int n; cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    for(int j = 0; j < 20; j++){
        for(int i = 0; i < n; i++){
            if(j == 0){
                sparse[i][j] = a[i];
            }
            else{
                sparse[i][j] = max(sparse[i][j-1], sparse[min(n - 1, i + (1 << (j - 1)))][j-1]);
            }
        }
    }
    
    int m; cin >> m;
    
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        x--; y--;
        if(x > y){
            swap(x, y);
        }
        int length = lg[y - x];
        
        int sol = max(sparse[x][length], sparse[y-(1<<length)+1][length]);
        
        cout << sol << endl;
        
    }
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}