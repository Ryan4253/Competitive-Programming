#include<iostream>
using namespace std;
int main(){
	string s; cin >> s;
	int n; n = s.size();
	int atkcnt = 0;
	
	for(int i = 0; i < n; i++){
		if(s[i] == 'A' && s[i+1] == 'C'){
			atkcnt ++;
		}
	}
	
	cout << atkcnt << endl;
}

