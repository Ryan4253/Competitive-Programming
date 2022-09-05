#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

void solve(){
	int n; cin >> n;
	vector<pair <int, int> > v;
	int temp1, temp2;
	v.pb(make_pair(0,0));
	
	for(int i = 0; i < n; i++){
		cin >> temp1 >> temp2;
		v.pb(make_pair(temp1, temp2));
	}
	sort(v.begin(), v.end());
	
	bool flag = true;
	for(int i = 0; i < n; i++){
		if(v[i].second > v[i+1].second){
			flag = false;
		}
	}
	
	if(flag){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
		return;
	}
	
	for(int i = 0; i < n; i++){
		temp1 = v[i+1].first - v[i].first;
		temp2 = v[i+1].second - v[i].second;
		for(int i = 0; i < temp1; i++){
			cout << 'R';
		}
		for(int i = 0; i < temp2; i++){
			cout << 'U';
		}
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

