#include<iostream>
using namespace std;
int main(){
	string s; cin >> s;
	int x; x = s.size();
	
	int acnt = 0, bcnt = 0, ccnt = 0, ult = 0;
	for(int i = 0; i < x; i++){
		if(s[i] == 'A'){
			acnt++;
		}
		if(s[i] == 'B'){
			bcnt++;
		}
		if(s[i] == 'C'){
			ccnt++;
		}
		if(s[i] == 'X'){
			if(acnt >= 3 && bcnt >= 2 && ccnt >= 1){
				ult ++;
			}
		acnt = 0; bcnt = 0; ccnt = 0;
		}
	} 
	
	cout << ult << endl;

}

