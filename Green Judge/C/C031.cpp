//killer queen have already touched the code
#include<iostream>
using namespace std;
int main(){
	int ppl, dice; cin >> ppl >> dice;
	int a[ppl];
	for(int i = 0; i < ppl; i++){
		a[i] = 1;
	} 
	
	int runs = dice * (ppl-1);
	int tmpcnt = 0;
	int x = 0;
	
	while(runs != 0){
		if(a[x%ppl] == 1){
			tmpcnt ++;
			runs--;
		}
		if(tmpcnt == dice){
			a[x%ppl] = 0;
			tmpcnt = 0;
		}
		x++;
	}
	
	for(int i = 0; i < ppl; i++){
		if(a[i] == 1){
			cout << i + 1 << endl;
			return 0; 
		}
	}
}


