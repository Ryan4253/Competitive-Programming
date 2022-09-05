#include<iostream>  
using namespace std;  
  
int main(){  
    int n = 0, x = 0;  
    cin >> n;  
      
    for(int i = 1; i <= n; i++){  
        for(int j = 0; j < n; j++){  
            if(j%3 == x){  
                cout << "@";  
            }  
            else{  
                cout << "-";  
            }  
        }  
        cout << endl;  
        x = (x + 1) % 3;  
    }  
}  
