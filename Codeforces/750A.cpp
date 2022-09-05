#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

void solve(){
	int a, b; cin >> a >> b;
	int time = 240 - b;
	time /= 5;
	int n = 1;
	int cnt = 0;
	while(time >= n && n <= a){
		time -= n;
		n++;
	}
	n--;
	cout << n << endl; 
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}

