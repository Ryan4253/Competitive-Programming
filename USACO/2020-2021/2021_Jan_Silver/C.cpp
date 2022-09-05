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

void solve(){
	int n; cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    
    int sol = 0;
    int odd = 0, even = 0;

    for(int i = 0; i < n; i++){
    	for(int j = 0; j < n; j++){
    		if(j % 2 == 1){
    			even += a[i][j];
    		}
    		else{
    			odd += a[i][j];
    		}
    	}
    	sol += max(odd, even);
    	odd = 0, even = 0;
    }

    int sol2 = 0;
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < n; j++){
    		if(j % 2 == 1){
    			even += a[j][i];
    		}
    		else{
    			odd += a[j][i];
    		}
    	}
    	sol2 += max(odd, even);
    	odd = 0, even = 0;
    }
    
    cout << max(sol, sol2) << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}