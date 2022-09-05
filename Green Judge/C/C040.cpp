#include<iostream>
using namespace std;
int main(){
	int a, b; cin >> a >> b;
	int mod = a%b;
	int ora = a;
	int orb = b;
	while(mod != 0){
		if(a>=b){
			mod = a%b;
			cout << a << "%" << b << "=" << mod << endl;;
			a = b;
			b = mod;
		}
	}
	cout << "GCD(" << ora << "," << orb << ")=" << a << endl;
	
}

