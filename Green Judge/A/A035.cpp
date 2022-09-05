#include<iostream>
#include<math.h>
using namespace std;

int main(){
	int a = 0, b = 0; cin >> a >> b;
	int n = 0;
	
	n = b*log10(a);
	n = round(n);
	cout << n+1 << endl;
	
} 
