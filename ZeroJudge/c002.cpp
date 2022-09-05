#include<iostream>
#include<sstream>
using namespace std;

int f(int n) {
    if (n >= 101) return n - 10;
    else return f(f(n + 11));
}

int main(){
	int n;
	while(cin >> n){
		if(n == 0){
			break;
		}
		else{
			cout << "f91(" << n << ") = " << f(n) << endl;
		}
	}	
}

