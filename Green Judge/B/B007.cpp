#include<iostream>
using namespace std;
int main(){
	int x = 0;
	string s;
	cin >> s;
	x = s.size();
	
	for(int i = x-1; i >= 0; i--){
		cout << s[i];
	}
 
}
