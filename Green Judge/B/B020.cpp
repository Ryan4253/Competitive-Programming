#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

void solve(){
	int n; cin >> n;
	vector<string> v;
	string temp;
	for(int i = 0; i < n; i++){
		cin >> temp;
		v.pb(temp);
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < n; i++){
		cout << v[i] << endl;
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}

