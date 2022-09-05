#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

const int N = 500;
int a[N][N];
vector<pii> hun;

int h[N];

ll int calculate(int n){
    for(int i = 0; i < n; i++){
        h[i] = 0;
    }
    ll int sol = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j] == 0){
                h[j] = 0;
            }
            else{
                h[j]++;
            }
        }
        
        for(int l = 0; l < n; l++){
            int mn = h[l];
            for(int r = l; r < n; r++){
            	mn = min(mn, h[r]);
                sol += mn;
                if(mn == 0){
                    break;
                }
            }
        }
    }
    
    return sol;
}

void solve(){
	int n; cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int g; cin >> g;
            if(g == 100){
                hun.pb(mp(i, j));
                a[i][j] = 0;
            }
            else if(g > 100){
                a[i][j] = 1;
            }
            else{
                a[i][j] = 0;
            }
        }
    }
    
    ll int l = calculate(n);
    
    for(int i = 0; i < hun.size(); i++){
        a[hun[i].F][hun[i].S] = 1;
    }
    
    ll int r = calculate(n);
    
    cout << r - l << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}