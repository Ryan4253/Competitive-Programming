#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

void solve(){
	int n; cin >> n;
	int a[n];
	
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a, a+n);
	
	int mid, midleft, midright;
	midleft = n / 2 - 1;
	
	if(n % 2 == 1){
		cout << a[n / 2] << " ";
		midright = n / 2 + 1;
	}
	else{
		midright = n / 2;
	}
	
	for(int i = 0; i < n/2; i++){
		cout << a[midleft-i] << " " << a[midright+i] << " ";
	}
	
	cout << endl;
	
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		solve();
	}
	
}

