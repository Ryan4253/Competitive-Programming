#include<iostream>
using namespace std;
int main(){
	int a, b, c; cin >> a >> b >> c;

	if(a > 600){
		a = 600;
	}
	if(b > 600){
		b = 600;
	}
	if(c > 800){
		c = 800;
	}
	if(a + b >= 1000){
		a = 0; b = 1000;
	}
	if(a + b + c >= 1500){
		a = 0; b = 0; c = 1500;
	}
	cout << a + b + c << endl;
}

