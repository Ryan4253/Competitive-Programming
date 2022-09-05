#include<iostream>
using namespace std;
int main(){
	int a = 0, b = 0, c = 0, d = 0, e = 0; cin >> a >> b >> c >> d >> e;
	int f = 0, g = 0;
	f = a + c + e;
	g = b + c + d;
	a = a + b;
	d = d + e;
	
	if(a < d && a < f && a < g){
		cout << a << endl;
	}
	else if (d < a && d < f && d < g){
		cout << d << endl;
	}
	else if (f < d && f < a && f < g){
		cout << f << endl;
	} 
	else if (g < d && g < f && g < a){
		cout << g << endl;
	}
	else{
		cout << a << endl;
	}
}
