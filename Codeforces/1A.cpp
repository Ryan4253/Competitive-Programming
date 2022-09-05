#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ll int n, m, a; cin >> n >> m >> a;
	if(n % a != 0){
		n = n + a - n % a;
	}
	if(m % a != 0){
		m = m + a - m % a;
	}
	cout << (n / a) * (m / a) << endl;
}

