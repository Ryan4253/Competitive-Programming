#include <iostream>  
using namespace std;  
  
int main () {  
    int n = 0, m = 0, a = 0, b = 0; cin >> n;  
    int x[n];  
    for (int i = 0; i < n; i++){  
        cin >> x[i];  
    }  
    cin >> m;  
      
    for (int i = 0; i <= n-1; i++){  
        if (m < x[i]){  
            a++;  
        }  
        else if(m > x[i]){  
            b++;  
        }     
    }  
    cout << a << " " << b << endl;  
          
}  
