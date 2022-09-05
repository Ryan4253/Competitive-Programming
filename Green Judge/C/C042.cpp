#include<iostream>
using namespace std;
int main(){
	string s; cin >> s;
	int n = 0; n = s.size();
	s = s + 'f';
	int tmp = 0;
	int max = 0;
	for(int i = 0; i <= n; i++){
		if(s[i] == 'F'){
			tmp ++;
		}
		if(s[i] == 'f'){
			if(tmp > max){
				max = tmp;
			}
			tmp = 0;
		}
	}
	
	cout << max << endl;
}

