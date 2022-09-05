#include<iostream>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

void solve(){
	ll int cost, disc; cin >> cost >> disc;
	
	ll int avadisc = disc / 10 * 10;
	ll int maxdisc = cost / 10;
	
	cost -= min(maxdisc, avadisc);
	disc -= min(maxdisc, avadisc);
	
	disc += cost / 100;
	
	cout << cost << " " << disc << endl;
	
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}

