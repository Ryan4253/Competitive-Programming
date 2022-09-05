#include<bits/stdc++.h>
using namespace std;
int main(){
	string s; cin >> s;
	string s1;
	
 		if(s[i] < 97){
			s[i] += 32;
		}
		if(s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u' && s[i] != 'y'){
			s1 += s[i]; 
		}
	}
	
	for(int i = 0; i < s1.size(); i++){
		cout << "." << s1[i];
	}
	cout << endl;
}

