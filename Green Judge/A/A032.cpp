#include <iostream>  
using namespace std;  
  
int main () {  
    int a = 0, b = 0;  
    char c;  
    cin >> a >> c >> b;  
    if (c == '+') {  
        cout << a + b << endl;  
    }  
    else if (c == '-') {  
        cout << a - b << endl;  
    }  
    else if (c == '*') {  
        cout << a * b << endl;  
    }  
}  
