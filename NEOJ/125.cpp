#include<bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define ll long long
#define pb push_back

const int N = 1000000 + 5;
const int X = 10000019;
int a[N];
int temp[N];




int invpair(int l, int r){
    int sol = 0;
    if(l + 1 == r){
        return 0;
    }
    
    int mid = (l + r) / 2;
    sol += invpair(l, mid) % X;
    sol += invpair(mid, r) % X;
    int ptr = mid;
    ll int sum = 0;
    
    for(int i = l; i < mid; i++){
        while(ptr < r && a[i] > a[ptr]){
            sum += a[ptr];
            sum %= X;
            ptr++;
        }
        sol += ((sum + (ptr - mid) * 1ll * a[i])) % X;
        sol %= X;
    }
    
    int lptr = l, rptr = mid;
    int tempptr = 0;
    while(lptr < mid || rptr < r){
        if(lptr == mid || r != rptr && a[lptr] >= a[rptr]){
            temp[tempptr] = a[rptr];
            rptr++;
        }
        else{
            temp[tempptr] = a[lptr];
            lptr++;
        }
        tempptr++;
    }
    
    for(int i = l; i < r; i++){
        a[i] = temp[i-l];
    }
    return sol;
};

void solve(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << invpair(0, n) << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
    solve();
}
