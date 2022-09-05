#include<bits/stdc++.h>
using namespace std;
int main(){
	string s, t; cin >> s >> t;
	for(int i = 0; i < s.size(); i++){
		if(s[i] < 97){
			s[i] += 32;
		}
		if(t[i] < 97){
			t[i] += 32;
		}
	}
	for(int i = 0; i < s.size(); i++){
		if(s[i] > t[i]){
			cout << "1" << endl;
			return 0;
		}
		else if (s[i] < t[i]){
			cout << "-1" << endl;
			return 0;
		}
	}
	cout << "0" << endl;
}

