#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

void solve(){
	int n; cin >> n;
	vector<int> v;
	int tempcnt = 0;
	int temp;
	for(int i = 0; i < n; i++){
		cin >> temp;
		if(temp == 0){
			tempcnt++;
		}
		else if(temp != 0 && tempcnt > 0){
			v.pb(-tempcnt);
			v.pb(temp);
			tempcnt = 0;
		}
		else{
			v.pb(temp);
		}
	}
	
	int no[2];
	no[0] = n / 2;
	no[1] = (n + 1)/2;
	
	for(int i = 0; i < n; i++){
		if(v[i] > 0){
			if(v[i] % 2 == 0){
				no[0]--;
			}
			else{
				no[1]--;
			}
			v[i] %= 2;
		}
	}
	
	int one_zero = 0;
	int one_one = 0;
	int zero_zero = 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n = 1;
	while(n--){
		solve();
	}
}

