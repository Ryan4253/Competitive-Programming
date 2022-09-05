#include<iostream>  
using namespace std;  
int main(){  
    int a = 0, b = 0, c = 0;  
    cin >> a >> b;  
    c = a * 60 + b;  
      
    if(c >= 860 && c <= 1000){  
        cout << "YES" << endl;  
    }  
    else{  
        cout << "NO" << endl;  
    }  
}   
