#include<iostream>  
using namespace std;  
int main(){  
    int n = 0, a = 1;  
    cin >> n;  
      
    while (n != 1){  
        if(n % 2 == 1){  
            n = 3 * n + 1;  
        }  
        else{  
            n = n / 2;  
        }  
        a = a + 1;  
    }  
    cout << a << endl;  
}  
