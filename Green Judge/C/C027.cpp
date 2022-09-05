#include<iostream>
using namespace std;
int main(){
	int h, m; cin >> h >> m;
	
	if(h <= 7 && m < 30 || h >= 17){
		cout << "XXX" << endl;
	}
	else if(m < 10 || (h == 12 && m < 30)){
		cout << "NO" << endl;
	}
	else{
		cout << "YES" << endl;
	}
}

