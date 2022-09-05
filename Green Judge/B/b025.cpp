#include<iostream>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

const int N = 32 + 1;
ll int a[N][N];

void fill(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i == 0 || j == 0){
                a[i][j] = 1;
            }
        }
    }
    
    
    for(int i = 1; i < N; i++){
        for(int j = 1; j < N; j++){
            a[i][j] = a[i][j-1] + a[i-1][j];
        }
    }
}

void solve(){
    fill();
    int x, y; cin >> x >> y;
    cout << a[x][y] << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
    solve();
}
