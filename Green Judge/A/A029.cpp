#include<iostream>  
using namespace std;  
int main(){  
    int a = 0, b = 0, c = 0;  
    cin >> a >> b;  
      
    for(int i = a; i <= b; i++) {  
        c = c + i;  
        cout << i;  
        if(i == b){  
            break;  
        }  
        cout << "+";    
    }  
      
    cout << "=" << c << endl;  
}   	
