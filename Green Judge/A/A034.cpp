#include<iostream>  
#include<iomanip>  
#include<math.h>  
using namespace std;  
int main(){  
    double a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0;  
    cin >> a >> b >> c >> d;  
    e = c - a;  
    f = d - b;  
    e = e*e;  
    f = f*f;  
    g = e + f;  
    g = sqrt(g);   
  
  
    cout << fixed << setprecision(3) << g << endl;  
  
}   
