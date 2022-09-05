#include <iostream>  
using namespace std;  
int main(){  
    int N=0;  
    cin >> N;  
      
    if (N % 4 == 0 && N % 100 != 0 || N % 400 == 0){  
        cout << "YES" << endl;  
    }  
      
    else{  
        cout << "NO" << endl;  
    }  
}  
