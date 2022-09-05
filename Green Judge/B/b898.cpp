#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

void solve(){
	string a[3];
	for(int i = 0; i < 3; i++){
		cin >> a[i];
	}
	
	if(a[0].size() >= a[1].size() && a[0].size() >= a[2].size()){
		while(a[0].size() != a[1].size()){
			a[1] = '0' + a[1];
		}
		while(a[0].size() != a[2].size()){
			a[2] = '0' + a[2];
		}
	}
	else if(a[1].size() >= a[0].size() && a[1].size() >= a[2].size()){
		while(a[0].size() != a[1].size()){
			a[0] = '0' + a[0];
		}
		while(a[2].size() != a[1].size()){
			a[2] = '0' + a[2];
		}
	}
	else if(a[2].size() >= a[1].size() && a[2].size() >= a[0].size()){
		while(a[2].size() != a[1].size()){
			a[1] = '0' + a[1];
		}
		while(a[0].size() != a[2].size()){
			a[0] = '0' + a[0];
		}
	}
	sort(a, a+3);
	
	cout << a[0] << endl;
	
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		solve();
	}
}

