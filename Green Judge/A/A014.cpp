#include <iostream>   
using namespace std;  
int main(){  
    int a=0, b=0, c=0, d=0;  
    cin >> a >> b >> c;  
    if(a <= b){  
        d = a;  
    }  
      
    else{  
        d = b;  
    }  
      
    if(c <= d){  
        d = c;  
    }  
    cout << d << endl;    
}  
