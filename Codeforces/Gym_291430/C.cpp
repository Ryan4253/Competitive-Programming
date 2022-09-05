#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

const int N = 100000+5;
int a[N];

void solve(){
	int n; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    ll int sum = 0; ll int bit = 0;
    for(int i = 0; i < n; i++){
        sum += a[i];
        bit ^= a[i];
    }
    
    cout << "2" << endl;
    cout << bit << endl;
    cout << sum + bit << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	ll int n; cin >> n;
	while(n--){
		solve();
	}
}
