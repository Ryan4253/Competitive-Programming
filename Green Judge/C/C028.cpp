#include<bits/stdc++.h>
using namespace std;
int main(){
	int exp; cin >> exp;
	if(exp < 10){
		cout << "1 " << 10 - exp << endl; 
		return 0;
	}
	exp -= 10;
	int lv = 2;
	int expreq = 14;
	
	while(exp >= expreq){
		exp = exp - expreq;
		lv ++;
		expreq = expreq * 2 - lv * 3;
		
	}
	cout << lv << " " << expreq - exp;
}

