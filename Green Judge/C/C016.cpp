#include<iostream>
using namespace std;
int main(){
	int min, max; cin >> min >> max;
	int cnt = 0;
	for(int i = min; i <= max; i++){
		if(i % 2 != 0 && i % 3 != 0 && i % 5 != 0){
			cnt++;
		}
	}
	
	cout << cnt << endl;
}

