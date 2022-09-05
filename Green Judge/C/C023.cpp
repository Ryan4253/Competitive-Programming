#include<iostream>
using namespace std;

int main(){
	int n; cin >> n;
	int a[2*n];
	
	for(int i = 0; i < 2 * n; i++){
		cin >> a[i];
	}
	
	int sol[n];
	int max = 0;
	int ptr = 0;
	
	for(int i = 0; i < n; i ++){
		sol[i] = a[2 * i]*a[2 * i] + a[(2 * i)+1] * a[(2 * i)+1]; 
		if(sol[i] > max){
			max = sol[i];
			ptr = i + 1;
		}
	}
	
	cout << ptr << " " << max << endl;
}

