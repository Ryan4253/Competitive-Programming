#include<iostream>
using namespace std;
int main(){
	int n = 0; cin >> n;
	int a[n];
	
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	int x = 0, y = 0, z = 0, lmao = 0;
	for(int i = 0; i < n; i++){
		if(a[i] == 1){
			x++;
		}
		else if(a[i] == 2){
			y++;
		}
		else if(a[i] == 3){
			z++;
		}
		else{
			lmao++;
		}	
	}
	
	cout << x << " " << y << " " << z << " " << lmao << endl;

}

