#include<iostream>
using namespace std;

int main (){
	int n = 0; cin >> n;
	int a = 0, b = 0;
	
	for (int i = 1; i <= n; i++){
		cin >> a >> b;
		cout << "Case " << i << ": ";
		if (a == b){  
            cout << "0" << endl;  
        }  
        else if (a < b){    
            cout << "B " << b-a << endl;  
        }  
        else if (a > b){   
            cout << "A " << a-b << endl;  
        }  
	} 

		
		
}
