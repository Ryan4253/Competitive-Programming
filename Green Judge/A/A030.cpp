#include<iostream>  
using namespace std;  
int main(){  
    int a = 0, b = 0, c = 0, d = 0; //a is imput, b is swapped  
    cin >> a >> b;  
    cout << a;  
      
    if (a < b){  
        for(int i = a; i < b; i++){  
        cout << "+" << i+1;   
        }  
        for (int d = a; d <= b; d++){  
        c = c + d;  
        }   
    }  
      
    else if (a > b){  
        for(int i = a; i > b; i--){  
        cout << "+" << i-1;  
        }         
        for (int d = b; d <= a; d++){  
        c = c + d;  
        }   
    }  
      
    else{  
        c = a;  
    }  
  
      
      
      
    cout << "=" << c << endl;   
}   
