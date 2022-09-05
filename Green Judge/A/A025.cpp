#include<iostream>  
using namespace std;  
int main(){  
    int a = 0, b = 0; //a is imput, b is swapped  
    cin >> a;  
      
    while (a != 0){  
        b = 10 * b + a % 10;  
        a = a / 10;   
    }  
    cout << b << endl;  
}   
