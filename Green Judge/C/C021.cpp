#include<iostream>
using namespace std;
int main(){
	int amin, bmin, cmin; cin >> amin >> bmin >> cmin;
	int a, b, c;
	a = amin + 3 * bmin + 5 * cmin;
	b = amin * 3 + bmin * 2 + cmin * 4;
	c = (amin + bmin + cmin) * 3;
	
	if(a <= b && a <= c){
		cout << "A " << a << endl;
		return 0;
	}
	else if(b <= a && b <= c){
		cout << "B " << b << endl;
		return 0;
	}
	else if(c <= a && c <= b){
		cout << "C " << c << endl;
		return 0;
	}
}

