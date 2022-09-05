#include<iostream>
using namespace std;
int main(){
	int n = 0, x = 0; cin >> n;
	int a[n];
	int b[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	for(int i = 0; i < n; i++){
		b[i] = 0;
		for (int j = 0; j < n; j++){
			if(a[i] == a[j]){
				b[i]++;
			}
		}
	}
	
	for(int i = 0; i < n; i++){
		if(b[i] > b[x]){
			x = i;
		}
	}
	
	cout << a[x] << " " << b[x];	
} 
