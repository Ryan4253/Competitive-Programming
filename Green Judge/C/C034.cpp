#include<iostream>
using namespace std;
int main(){
	int a, n; cin >> a >> n;
	for(int i = 0; i < n; i++){
		a = (a * 7) % 100;
		a = a % 10 * 10 + a / 10;
	}
	cout << a << endl;
}

