#include<iostream>
using namespace std;
int main(){
	int a = 0, b = 0; cin >> a >> b;
	
	if(a >= 0 && a <= 29){
		cout << "1 ";
	}
	else if(a >= 30 && a <= 49){
		cout << "2 ";
	}
	else if(a >= 50 && a <= 69){
		cout << "3 ";
	}
	else if(a >= 70 && a <= 89){
		cout << "4 ";
	}
	else if(a >= 90 && a <= 100){
		cout << "5 ";
	}
	
		if(b >= 0 && b <= 49){
		cout << "1";
	}
	else if(b >= 50 && b <= 149){
		cout << "2";
	}
	else if(b >= 150 && b <= 249){
		cout << "3";
	}
	else if(b >= 250 && b <= 349){
		cout << "4";
	}
	else if(b >= 350 && b <= 400){
		cout << "5";
	}
}
