#include<iostream>
using namespace std;
int main(){
	int a = 0, b = 0; cin >> a >> b;
	
	while (a != 0 && b != 0){
		if (a >= b){
			a = a % b;
		}
		else if (b > a){
			b = b % a;
		}
	}
	
	if (a != 0){
		cout << a << endl;
	}
	else if (b != 0){
		cout << b << endl;
	}
}
