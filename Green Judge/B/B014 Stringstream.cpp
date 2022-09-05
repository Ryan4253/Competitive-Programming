#include<iostream>
#include<sstream>
using namespace std;
int main(){
	int mx = 0, mx_id = 0;
	for(int i = 1; i <= 3; i++){
		string s;
		getline(cin, s);
		stringstream ss;
		ss.str(s);
		
		int sum = 0, x;
		while(ss >> x){
			sum += x;
		}
		if(sum >mx){
			mx = sum;
			mx_id = i;
		}
		
	}
	
		cout << mx_id << " " << mx << endl;

}
