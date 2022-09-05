#include<iostream>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

const int N = 100;
ll int a[N];

void fibonacci(){
    a[1] = 1; a[2] = 2;
    for(int i = 3; i <= 90; i++){
        a[i] = a[i-1] + a[i-2];
    }	
}

void solve(){
    fibonacci();    
    int n; cin >> n;
    cout << a[n] << " " << a[a[n]%n] << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
    solve();
}
