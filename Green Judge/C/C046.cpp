#include<iostream>
using namespace std;
int main(){
	int a = 0, b = 0, c = 0 , n = 0; cin >> a >> b >> n;
	c = a / b;
	cout << c << ".";
	a = a % b;
	for(int i = 1; i <= n; i++){
		a = a * 10;
		c = a / b;
		cout << c;
		a = a % b;
	}
} 
