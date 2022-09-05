#include<iostream>
using namespace std;
int main(){
	int T = 0; cin >> T;
	for(int j = 1; j <= T; j++) {
		int n = 0, x = 0; cin >> n;
		string s; cin >> s;
		x = s.size();
		for(int i = 0; i < x; i++){
		s[i] = s[i] - 'A';
		s[i] = (s[i] - n + 26)%26 + 'A';
	}
	
	cout << s << endl;
		
	}
} 
