#include <iostream>  
using namespace std;  
  
int main () {  
    int n = 0, c = 0, d = 0; cin >> n;  
    int a[n];  
    for (int i = 0; i < n; i++){  
        cin >> a[i];  
    }  
      
    for (int i = 0; i <= n-1; i++){  
        if (c < a[i]){  
            c = a[i];  
            d = i;  
        }     
    }  
    cout << d+1 << " " << c << endl;  
          
}  #include <iostream>  
using namespace std;  
  
int main () {  
    int n = 0, c = 0, d = 0; cin >> n;  
    int a[n];  
    for (int i = 0; i < n; i++){  
        cin >> a[i];  
    }  
      
    for (int i = 0; i <= n-1; i++){  
        if (c < a[i]){  
            c = a[i];  
            d = i;  
        }     
    }  
    cout << d+1 << " " << c << endl;  
          
} 
