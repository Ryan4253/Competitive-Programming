#include<iostream>
using namespace std;
int main(){
	int n = 0; cin >> n;
	int c = 0;
	int a[n];
	for (int i = 0; i < n; i++){  
        cin >> a[i];  
    } 
    
    for (int i = 0; i < n; i++){
    	a[i] = (a[i]-2)*(a[i]-2);
    	c = c + a[i];
	}
    
    cout << c << endl;
} 
