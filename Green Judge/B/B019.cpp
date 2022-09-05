#include<iostream>
using namespace std;
int main(){
	int n; cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	int sol[n];
	int max = 0, ptr = 0;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(a[j] > max){
				max = a[j];
				ptr = j;
			} 
		}
		
		sol[i] = max;
		a[ptr] = 0;
		max = 0; ptr = 0;
	} 
	
	for(int i = 0; i < n; i++){
		cout << sol[i] << " ";
	}
	cout << endl;
}

