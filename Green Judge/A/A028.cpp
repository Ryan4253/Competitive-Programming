#include<iostream>  
using namespace std;  
int main(){  
    int n = 0, r = 0, p = 1;  
    cin >> n >> r;  
      
    for(int i = n - r + 1; i <= n; i++){  
        p = i * p;  
    }  
    cout << p << endl;   
}  
