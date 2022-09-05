#include<iostream>  
using namespace std;  
int main (){  
    int n = 0; cin >> n;  
    int c = 0;  
    cout << "|";  
  
    if(n >= 1 && n < 10){  
        cout << "_______";  
        cout << n;  
    }  
      
    else if(n >= 10 && n <= 100){  
        cout << "______";  
          
        for(int i = 10; i >= 1; i = i / 10){   
            c = n / i;  
            cout << c;  
            n = n - i * (n / i);  
        }  
    }  
      
    else if(n >= 100 && n <= 1000){  
        cout << "_____";  
          
        for(int i = 100; i >= 1; i = i / 10){   
            c = n / i;  
            cout << c;  
            n = n - i * (n / i);  
        }  
    }  
      
    else if(n >= 1000){  
        cout << "____";  
        n = n % 10000;  
          
        for(int i = 1000; i >= 1; i = i / 10){   
            c = n / i;  
            cout << c;  
            n = n - i * (n / i);  
        }  
    }  
      
    cout << "|" << endl;  
}   
