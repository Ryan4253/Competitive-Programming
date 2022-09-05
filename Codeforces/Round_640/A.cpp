#include<iostream>
#include<math.h>
using namespace std;

int main(){
	int x = 0; cin >> x;
	int a = 0;
	int power = 0;
	int cnt = 0;
	int c = 0;
	
	for(int i = 0; i < x; i++){
		cin >> a;
		c = a;
		
		while (c != 0){
				if(c % 10 != 0){
					cnt = cnt + 1;
				}	
				c = c / 10;
			}
		cout << cnt << endl;
		
		while (a != 0){	
			

			if(a % 10 != 0){
				cout << (a % 10) * pow(10, power) << " ";
				a = a / 10;
			}
			else{
				a = a / 10;
			}
		power = power + 1;
		}
	cout << endl;
	power = 0;
	cnt = 0;
}
	
	
	
	
	
}

