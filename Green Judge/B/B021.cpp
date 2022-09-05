#include<iostream>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

int a[9] = {1, 5, 10, 50, 100, 500, 1000, 5000, 10000};

void solve(){
	int count = 0;
	int n; cin >> n;
	
	for(int i = 8; i >= 0; i--){
		count += n / a[i];
		n %= a[i];
	} 
	
	cout << count << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}

