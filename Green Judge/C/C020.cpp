#include<iostream>
using namespace std;
int main(){
	int n = 0; cin >> n;
	n++;
	if(n <= 20){
		cout << "60" << endl;
		return 0;
	}
	else if (n <= 50){
		cout << "80" << endl;
		return 0;
	}
	else if (n <= 100){
		cout << "90" << endl;
		return 0;
	}
	else{
		cout << "100" << endl;
	}
}

