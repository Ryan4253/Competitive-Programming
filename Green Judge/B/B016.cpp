#include<iostream>
#include<string> 
using namespace std;
int main(){
	string a, b;
	cin >> a >> b;
	int x, y;
	x = a.size(); y = b.size();
	
	if (x > y){
		for(int i = 1; i <= x - y; i++){
			b = '0' + b;
		}
	}
	
	if (x < y){
		for(int i = 1; i <= y - x; i++){
			a = '0' + a;
		}
	}
	
	string sum = "";
	string tmp = " ";
	
	for(int i = (a.size()-1); i >= 0; i--){	
		if(a[i+1] + b[i+1] >= 106){
			tmp[0] = '0' + ((a[i]+b[i]-95)%10);
			a[i] = a[i] + 1;
			sum = tmp + sum;
		}
		else{
			tmp[0] = '0' + ((a[i]+b[i]-96)%10);
			sum = tmp + sum; 
		}
	}
	
	if(a[0] + b[0] >= 106){
		sum = "1" + sum;
	}
	
	cout << sum << endl;
}
