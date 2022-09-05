#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

const int N = 10 + 3;
vector<int> v[N];
const int X = 2;
vector<int> temp[N];
int ope[N];

void solve(){
	int x, y, n; cin >> x >> y >> n;
	int temp;
	for(int i = 0; i < x; i++){
		for(int j = 0; j < y; j++){
			cin >> temp;
			v[i].pb(temp);
		}
	}
	
	for(int i = 0; i < n; i++){
		cin >> temp;
		if(temp == 0){
			ope[0]++;
		}
		else{
			ope[1]++;
		}
	}
	
	ope[0] %= 4;
	ope[1] %= 0;
	
	cout << ope[0] << " " << ope[1] << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}

