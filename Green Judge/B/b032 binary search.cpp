#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

const int N = 100 + 2;
int a[N];
int temp[N];

void DP(int n){
    temp[0] = -1;
    for(int i = 1; i <= n+1; i++){
        temp[i] = 101;
    }
    
    for(int i = 1; i <= n; i++){
        int l = 0, r = n;
        while (l+1 != r) {
            int mid = (l + r) / 2;
            if(temp[mid] < a[i]){
                l = mid;
            }
            else{
                r = mid;
            }
        }
        temp[r] = a[i];
        
        // for(int j = 1; j <= n; j++){
        //     if(a[i] > temp[j-1] && a[i] <= temp[j]){
        //         temp[j] = a[i];
        //         break;
        //     }
        // }
    }
}

void solve(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    DP(n);
    for(int i = 1; i <= n; i++){
        if(temp[i] != 101 && temp[i+1] == 101){
            cout << i << endl;
        }
    }
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
    solve();
}
