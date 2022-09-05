#include<iostream>
using namespace std;
int main(){
	int n = 0; cin >> n;
	int a[n];
	int avg = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		avg += a[i];
	}
	avg /= n;
	
	int sol = 0;
	for(int i = 0; i < n; i++){
		a[i] -= avg;
		if(a[i] > 0){
			sol += a[i];
		}
	}
	
	cout << sol << endl;
}

