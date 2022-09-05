#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

void solve(){
	int a[4];
	for(int i = 0; i < 4; i++){
		cin >> a[i];
	}
	sort(a, a + 4);
	
	if(a[0] == a[3]){
		cout << "1000" << endl;
		return;
	}
	else if(a[0] == a[2] || a[1] == a[3]){
		cout << "100" << endl;
		return;
	} 
	else if(a[0] == a[1] && a[2] == a[3]){
		cout << "50" << endl;
		return;
	}
	else if(a[0] == a[1] || a[2] == a[3]){
		cout << "10" << endl;
		return;
	}
	else{
		cout << "0" << endl;
		return;
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}

