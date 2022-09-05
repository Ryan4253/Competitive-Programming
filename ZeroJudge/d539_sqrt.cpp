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
const int K = 710;
const int MIN = -2147483648;

int mx[N/K+10];
int a[N];



void solve(){
	int n; cin >> n;
    
    for(int i = 0; i < N/K+10; i++){
        mx[i] = MIN;
    }
    
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mx[i/K] = max(mx[i/K], a[i]);
    }
    
    int m; cin >> m;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        x--; y--;
        if(x > y){
        	swap(x, y);
        }
        int mngroup = x/K, mxgroup = y/K, sol = MIN;
            
        if(mngroup == mxgroup){
            for(int j = x; j <= y; j++){
                sol = max(sol, a[j]);
            }
        }
        else{
            for(int j = x; j/K == mngroup; j++){
                sol = max(sol, a[j]);
            }
            
            for(int j = mngroup+1; j <= mxgroup-1; j++){
                sol = max(sol, mx[j]);
            }
            
            for(int j = mxgroup * K; j <= y; j++){
                sol = max(sol, a[j]);
            }
        }
        
        cout << sol << endl;
    }
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}