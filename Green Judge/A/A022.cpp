#include<iostream>  
using namespace std;  
int main(){  
    int n = 0, m = 0, a = 0;  
    cin >> n >> m;  
      
    while (n < m){  
        n = 3 * n;  
        a = a + 1;  
    }  
    cout << a << endl;  
}  
