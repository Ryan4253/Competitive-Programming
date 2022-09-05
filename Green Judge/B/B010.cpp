#include<iostream>
using namespace std;
int main(){
	int x = 0;
	string s;
	cin >> s;
	x = s.size();
	
	for(int i = 0; i < x; i++){
		s[i] = s[i] - 2;
		if(s[i] == '?'){
			s[i] = 'Y';
		}
		else if(s[i] == '@'){
			s[i] = 'Z';
		}
	}
	
	cout << s;
}
