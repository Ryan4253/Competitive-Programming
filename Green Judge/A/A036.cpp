#include<iostream>  
#include<iomanip>  
#include<math.h>  
using namespace std;  
int main(){  
    int a = 0, b = 0, c = 0;  
    cin >> a >> b;  
      
    if(a>b){  
        c = a - b;  
        cout << "A " << c << endl;   
    }   
    else if (a<b){  
        c = b - a;  
        cout << "B " << c << endl;  
    }  
    else{  
        cout << "0" << endl;  
    }  
       
}   
