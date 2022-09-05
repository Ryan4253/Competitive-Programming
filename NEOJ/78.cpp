#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

int solve(ll int a[6]){
	ll int box = 0;
	ll int ava[2] = {0};
	//6 5 4
	box = a[5] + a[4] + a[3] + a[2] / 4;
	ava[0] += 11 * a[4];
	ava[1] += 5 * a[3];
	
	//3
	a[2] %= 4;	
	if(a[2] != 0){
		box++;
		ava[1] += (7-2*a[2]);
		ava[0] += (8 - a[2]);
	}
	
	//2
	
	for(int i = 1; i >= 0; i--){
		int temp = 36 / (i+1) / (i+1);
		ll int temp2 = a[i];
		a[i] -= min(a[i], ava[i]);
		ava[i] -= min(temp2, ava[i]);
		box += a[i]/temp;
		if(a[i] % temp != 0){
			box++;
			ava[i] += (temp - (a[i] % temp));
		}
		ava[0] += ava[1] * 4;
	}
		
	cout << box << endl;
	
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	ll int a[6]; bool flag = false;
	while(1){
		for(int i = 0; i < 6; i++){
			cin >> a[i];
			if(a[i] != 0){
				flag = true;
			}
		}
		if(!flag){
			return 0;
		}
		else{
			solve(a);
		}
		flag = false;
	}
}

