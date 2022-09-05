#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int a, b; cin >> a >> b;
	int x;
	x = abs(a - b);

	if(x <= 20){
		cout << 0*x << endl;
		return 0;
	}
	if(x <= 200){
		cout << (x - 20)*4 << endl;
		return 0;
	}
	if(x <= 400){
		cout << (x-200)*3 + 720 << endl;
		return 0;
	}
}

