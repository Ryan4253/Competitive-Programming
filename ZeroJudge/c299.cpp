#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

void solve(){
	int n; cin >> n;
	vector<int> v;
	int temp;
	for(int i = 0; i < n; i++){
		cin >> temp;
		v.pb(temp);
	}
	
	sort(v.begin(), v.end());
	bool flag = true;
	for(int i = 0; i < n-1; i++){
		if(v[i+1] - v[i] != 1){
			flag = false;
		}
	}
	
	cout << v.front() << " " << v.back() << " ";
	if(flag){
		cout << "yes" << endl;
	}
	else{
		cout << "no" << endl;
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}

