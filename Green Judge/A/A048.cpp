#include<iostream>  
using namespace std;  
int main(){  
    int n = 0;  
    cin >> n;  
      
    for(int i = 1; i <= n; i++){  
        for(int j = 0; j < n - i; j++){  
            cout << "_";  
        }  
        for (int j = 1; j <= 2 * i - 1; j++){  
            cout << i;  
        }  
        cout << endl;  
          
    }  
}  
