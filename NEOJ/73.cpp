#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

const int N = 100000 + 5;
int a[N];
int n, m;

bool check(int value){
    int tempsum = 0, reqppl = 1;
    for(int i = 0; i < n; i++){
        if(tempsum + a[i] > value){
            tempsum = a[i];
            reqppl++;
        }
        else{
            tempsum += a[i];
        }
        
    }
    
    if(reqppl <= m){
        return true;
    }
    else{
        return false;
    }
}

void solve(){
	cin >> n >> m;
    int sum = 0, max = 0;
    
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
        if(a[i] >= max){
            max = a[i];
        }
    }
    max -= 1;
    while(sum - max != 1){
        int value = (max+sum) / 2;
        if(check(value)){
            sum = value;
        }
        else{
            max = value;
        }
    }
    
    cout << sum << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        solve();
    }
}
