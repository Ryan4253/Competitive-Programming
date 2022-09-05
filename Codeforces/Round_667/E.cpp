#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

const int N = 200000 + 5;
int x[N];
int l[N]; // x[i] lenth when extended on the left
int r[N]; // yes
int lcnt[N];
int rcnt[N];
int suffix[N];

int Lbinarysearch(int i, int n){
    int left = -1, right = n;
    while(left + 1 != right){
        int mid = (left + right) / 2;
        if(l[i] > x[mid]){
            left = mid;
        }
        else{
            right = mid;
        }
    }
    return i - right + 1;
}

int Rbinarysearch(int i, int n){
	int left = 	-1, right = n;
    while(left + 1 != right){
        int mid = (left + right) / 2;
        if(r[i] >= x[mid]){
            left = mid;
        }
        else{
            right = mid;
        }
    }
    
    return left -i + 1;
}

void solve(){
    int n, m; cin >> n >> m;
    int temp;
    for(int i = 0; i < n; i++){
        cin >> x[i];
    }
    sort(x, x + n);
    for(int i = 0; i < n; i++){
        cin >> temp;
    }
    for(int i = 0; i < n; i++){
        l[i] = x[i] - m;
        r[i] = x[i] + m;
    }
    
    for(int i = 0; i < n; i++){
        lcnt[i] = Lbinarysearch(i, n);
        rcnt[i] = Rbinarysearch(i, n);
    }
    suffix[n-1] = rcnt[n-1];
    for(int i = n-2; i >= 0; i--){
        suffix[i] = max(suffix[i+1], rcnt[i]);
    }
    int maxsol = 0, tempsol;
    for(int i = -1; i < n; i++){
        tempsol = (i == -1 ? 0 : lcnt[i]) + (i == n - 1 ? 0 : suffix[i+1]);
        maxsol = max(maxsol, tempsol);
    }
    
    cout << maxsol << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--){
		solve();
 	}
}
