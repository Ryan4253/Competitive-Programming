#include<iostream>  
using namespace std;  
int main(){  
    int n = 0, a = 13;  
    cin >> n;  
      
    for(int i = 1; i < n; i++){  
        a = a * 13;  
        a = a % 100;  
    }  
      
    a = a / 10;  
    cout << a << endl;  
      
}  
