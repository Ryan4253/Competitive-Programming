#include<iostream>
using namespace std;
int main(){
	string s; cin >> s;
	int x; x = s.size();
	int scnt = 0;
	
	for(int i = 0; i < x; i++){
		if(s[i] == 'S'){
			scnt +=1;
		}
	}
	if(scnt * 100 / x >= 10){
		cout << "EUROPE" << endl;
	}
	else if (scnt * 100 / x < 2){
		cout << "AFRICA" << endl;
	}
	else{
		cout << "NORMAL" << endl;
	}
}

