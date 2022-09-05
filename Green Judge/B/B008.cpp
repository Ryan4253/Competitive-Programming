#include<iostream>
using namespace std;
int main(){
	int x = 0;
	string s;
	string t = "";
	
	cin >> s;
	x = s.size();
	t.resize(x);
	for(int i = x - 1; i >= 0; i--){
		t[x-i-1] = s[i];
	}
	
	if(s == t){
		cout << "YES" << endl; 
	}
	else{
		cout << "NO" << endl;
	}
}
