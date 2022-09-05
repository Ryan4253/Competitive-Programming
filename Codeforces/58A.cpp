#include<bits/stdc++.h>
using namespace std;
int main(){
	string s; cin >> s;
	
	while(1 == 1){
		if(s.empty()){
			cout << "NO" << endl;
			return 0;
		}
		else if (s[0] == 'h'){
			break;
		}
		s.erase(0, 1);
	}
	s.erase(0,1);
	
	while(1 == 1){
		if(s.empty()){
			cout << "NO" << endl;
			return 0;
		}
		else if (s[0] == 'e'){
			break;
		}
		s.erase(0, 1);
	}
	s.erase(0,1);
	
	while(1 == 1){
		if(s.empty()){
			cout << "NO" << endl;
			return 0;
		}
		else if (s[0] == 'l'){
			break;
		}
		s.erase(0, 1);
	}
	s.erase(0,1);
	
	while(1 == 1){
		if(s.empty()){
			cout << "NO" << endl;
			return 0;
		}
		else if (s[0] == 'l'){
			break;
		}
		s.erase(0, 1);
	}
	s.erase(0,1);
	
	while(1 == 1){
		if(s.empty()){
			cout << "NO" << endl;
			return 0;
		}
		else if (s[0] == 'o'){
			break;
		}
		s.erase(0, 1);
	}
	
	cout << "YES" << endl;
}

