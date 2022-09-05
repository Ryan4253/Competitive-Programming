#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

const int N = 100 + 2;
int a[N][N];
int dp[N][N];

void DP(int h, int w){
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            if(a[i][j] != 0){
                dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
            }
        }
    }
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
    int h, w; cin >> h >> w;
    int tmp;
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            cin >> tmp;
            if(tmp == 0){
                a[i][j] = 1;
            }
            else{
            	a[i][j] = 0;
            }
        }
    }
    DP(h, w);
    int mx = 0;
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            mx = max(dp[i][j], mx);
        }
    }
    cout << mx * mx << endl;
}
       
