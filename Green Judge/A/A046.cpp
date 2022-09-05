#include<iostream>
using namespace std;

int main(){
	int a = 0, b = 0; cin >> a >> b;
	
	for (int i = 1; i <= b; i ++){
		for(int j = 1; j <= a; j++){
			cout << "#";
		}
		cout << endl;
	}
}
