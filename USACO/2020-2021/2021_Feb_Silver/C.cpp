#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

const int N = 500 + 5;
int a[N][N];
int pre[N][N];

void build(int n){    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == 0 && j == 0){
                pre[i][j] = a[i][j];
            }
            else if(i == 0){
                pre[i][j] = pre[i][j-1] + a[i][j];
            }
            else if(j == 0){
                pre[i][j] = pre[i-1][j] + a[i][j];
            }
            else{
                pre[i][j] = pre[i][j-1] + pre[i-1][j] - pre[i-1][j-1] + a[i][j]; 
            }        
        }
    }
}


void solve(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int g; cin >> g;
            if(g == 100){
                a[i][j] = 50000;
            }
            else if(g > 100){
                a[i][j] = 1;
            }
            else{
                a[i][j] = -1;
            }
        }
    }
    
    build(n);
    int sol = 0;
    /*
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= n; j++){
    		cout << a[i][j] << " ";
    	}
    	cout << endl;
    }
    
    cout << endl;
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < n; j++){
    		cout << pre[i][j] << " ";
    	}
    	cout << endl;
    }
    */
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= i; k++){
                for(int l = 1; l <= j; l++){
                	//cout << i << " " << j << " " << k << " " << l << endl;
                    ll int sum = pre[k-1][l-1] + pre[i][j] - pre[i][l-1] - pre[k-1][j];
                    ll int hcnt = sum / 50000;
                    ll int blockcnt = (i - k+1) * (j - l+1);
                    //cout << sum << " " << hcnt << " " << blockcnt << endl;
                    if(hcnt > 0 && (blockcnt - hcnt + hcnt * 50000) == sum){
                        sol++;
                    }

                    //cout << endl;
                    
                }
            }
        }
    }
    
    
    
    cout << sol << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}