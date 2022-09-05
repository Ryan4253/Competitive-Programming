#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

const int N = 200000 + 7;
int a[N];
int pre[N];
int dp1[N];


/*
prefix_sum[N];
prefix_sum[i] = a[1] + a[2] + ... + a[i]; --> pre[i] = pre[i - 1] + a[i];
a[l] + ..... + a[r] --> pre[r] - pre[l - 1]
*/

void DP(int n){
    dp1[5] = 0;
    for(int i = 6; i <= n+5; i++){
        int temp1, temp2, temp3;
        
        if(pre[i] - pre[i-3] > 0){
            temp3 = dp1[i-3] + 1;
        }
        else{
            temp3 = dp1[i-3];
        }
        
        if(pre[i] - pre[i-2] > 0){
            temp2 = dp1[i-2] + 1;
        }
        else{
            temp2 = dp1[i-2];
        }
        
        if(a[i] > 0){
            temp1 = dp1[i-1] + 1;
        }
        else{
            temp1 = dp1[i-1];
        }
        
        dp1[i] = min(temp1, min(temp2, temp3));
    }
}

int go(int n){
    int ans = 0;
    for(int i = 5; i <= n+6; i++){
        if(a[i-1] > 0){
            a[i-1]--;
            ans++;
        }
        else if(a[i] > 0){
            a[i]--;
            ans++;
        }
        else if(a[i+1] > 0){
            a[i+1]--;
            ans++;
        }
    }
    return ans;
}


void solve(){
    int n; cin >> n;
    int temp;
    for(int i = 1; i <= n; i++){
        cin >> temp;
        temp += 5;
        a[temp]++;
    }
    pre[5] = a[5];
    for(int i = 5; i <= n+5; i++){
        pre[i] = pre[i-1] + a[i];
    }
    
    DP(n);
    cout << dp1[n+5] << " " << go(n) << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
    solve();
}
