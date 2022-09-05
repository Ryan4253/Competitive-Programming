#include<iostream>  
using namespace std;  
int main(){  
    int a = 0, b = 0;  
    cin >> a >> b;  
      
    if(b == 2 || b == 5 || b == 8){  
        cout << "200" << endl;  
    }  
      
    else if(a % 2 == 1){  
        cout << "100" << endl;  
    }  
      
    else if(a == b){  
        cout << "50" << endl;  
    }  
      
    else{  
        cout << "0" << endl;  
    }  
}   
