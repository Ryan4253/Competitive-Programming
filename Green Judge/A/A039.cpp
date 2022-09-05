#include<iostream>  
using namespace std;  
int main(){  
    int a = 0, b = 0, c = 0;  
      
    while(cin >> a >> b){  
        if (a == b){  
            cout << "0" << endl;  
        }  
        else if (a < b){  
            c = b - a;  
            cout << "B " << c << endl;  
        }  
        else if (a > b){  
            c = a - b;  
            cout << "A " << c << endl;  
        }  
    }  
}  
