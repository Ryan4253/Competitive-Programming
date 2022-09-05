#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

void solve(){
	int n, x; cin >> n >> x;
	int a[n], oddcnt = 0, evencnt = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(a[i] % 2 == 0){
			evencnt++;
		}
		else{
			oddcnt++;
		}
	}
	
	bool flag = 0;
	for(int i = 1; i <= oddcnt && i <= x; i+=2){
		if(evencnt >= x - i){
			flag = 1;
		}
	}
	
	if(flag){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}
	
	
	
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		solve();
	}
}

