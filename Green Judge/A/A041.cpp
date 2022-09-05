#include<iostream>  
using namespace std;  
int main(){  
    int n = 0, a = 0; // n = no bought, a = total gain  
    cin >> n;  
    a = n;  
    while(n / 5 != 0){  
        a = a + n / 5;  
        n = n % 5 + n / 5;  
    }  
      
    cout << a << endl;  
      
}  
