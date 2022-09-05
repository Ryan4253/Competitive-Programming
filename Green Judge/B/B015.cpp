#include<iostream>
#include<stdlib.h>
using namespace std;
int main(){
	string a , b , c;
	int x = 1;
	getline(cin, a);
	getline(cin, b);
	getline(cin, c);
	a = a + ' ';
	b = b + ' ';
	c = c + ' ';

	
	for(int i = 0; i < a.size(); i++){
		if(a[i] == 'B' && a[i+1] == 'I' && a[i+2] == 'L' && a[i+3] == 'L' && a[i+4] == ' '){
			cout << 1 << " " << x << endl;
			exit(0);
		}
		if(a[i] == ' '){
			x++;
		}
	}
	
	x = 1;
	
	for(int i = 0; i < b.size(); i++){
		if(b[i] == 'B' && b[i+1] == 'I' && b[i+2] == 'L' && b[i+3] == 'L' && b[i+4] == ' '){
			cout << 2 << " " << x << endl;
			exit(0);
		}
		if(b[i] == ' '){
			x++;
		}
	}
	
	x = 1;
	
	for(int i = 0; i < c.size(); i++){
		if(c[i] == 'B' && c[i+1] == 'I' && c[i+2] == 'L' && c[i+3] == 'L' && c[i+4] == ' '){
			cout << 3 << " " << x << endl;
			exit(0);
		}
		if(b[i] == ' '){
			x++;
		}
	}
	
	cout << "NO" << endl;
} 
