#include<iostream>
using namespace std;

int main(){
	int n = 0; cin >> n;
	int c = 0;
	
	for (int i = 1; i < n; i++){
		if(n % i == 0){
			c = c + i;
		}
	}
	
	if(c > n){
		cout << "Abundant" << endl;
	}
	else if(c < n){
		cout << "Deficient" << endl;
	}
	else{
		cout << "Perfect" << endl;
	}
}
