#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int, int>
#define pll pair<ll int, ll int>
#define pb push_back
#define mp make_pair
#define F first
#define S second

void solve(){
	vector<ll int> v;
	for(int i = 0; i < 7; i++){
		int temp; cin >> temp;
		v.pb(temp);
	}
	sort(v.begin(), v.end());

	do{
		bool flag = true;
		flag = (v[0]+v[1]==v[3]);
		flag = (v[1]+v[2]==v[4]);
		flag = (v[0]+v[2]==v[5]);
		flag = (v[0]+v[1]+v[2]==v[6]);
		
		if(flag){
			cout << v[0] << " " << v[1] << " " << v[2] << endl; 
			return;
		}
	}while(next_permutation(v.begin(), v.end()));
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}