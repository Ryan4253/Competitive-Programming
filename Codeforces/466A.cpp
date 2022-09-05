#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

void solve(){
	int n, m, a, b; cin >> n >> m >> a >> b;
	int price = 0;
	if(a * m >= b){
		while(n/m != 0){
			price += b;
			n-=m;
		}
		if(n * a <= b){
			price += n*a;
		}
		else{
			price += b;
		}
	
		cout << price << endl;
	}
	else{
		cout << n * a << endl;
	}
	
	
	
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}

