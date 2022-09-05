#include<iostream>
using namespace std;
int main(){
	int a = 0, b = 0, c = 0, d = 0; cin >> a >> b >> c;
	if(a == 7){
		d = 181 + b + c;
	}
	else if(a == 8){
		d = 212 + b + c;
	}
	
	if(d <= 242){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}
}
