#include<iostream>  
using namespace std;  
int main(){  
    int a = 0, b = 0; //a is imput, b is sum of digits, c is constant  
    cin >> a;  
      
    while (a != 0){  
        b = b + a % 10;  
        a = a / 10;   
    }  
    cout << b << endl;  
}  
