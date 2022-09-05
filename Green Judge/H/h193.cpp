#include<iostream>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

const int N = 5000 + 5;
ll int a[N];
ll int cost[N];

void solve(){
	ll int n, k; cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    for(int i = 0; i < n; i++){
        cin >> cost[i];
    }
    
    bool flag = false;
    ll int sol = 1e18;
    
    for(int i = 0; i < n; i++){
        if(a[i] < k){
            continue;
        }
        else if(a[i] == k){
            sol = 0;
            flag = true;
        }
        else{
            if(sol > cost[i]){
                sol = cost[i];
                flag = true;
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j || (a[i] + a[j]) < k){
                continue;
            }
            else if(a[i] + a[j] == k){
                sol = 0;
                flag = true;
            }
            else{
                if(a[i] < k && a[j] < k){
                    sol = min(sol, min(cost[i], cost[j]));
                    flag = true;
                }
            }
        }
    }
   
   cout << (flag ? sol : -1) << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--){
		solve();
	}
	
}