#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int n = 0; cin >> n;
	int a[n];
	int lcn[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	} 
	
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < n; j++){
			if(a[j] == i ){
				lcn[i-1] = j + 1;
			}
		}
	}
	
	int diff[n-1];
	for(int i = 0; i < n-1; i++){
		diff[i] = abs(lcn[i] - lcn[i+1]);
	}
	
	int sol = 0;
	for(int i = 0; i < n - 1; i++){
		sol += diff[i];
	}
	
	cout << sol << endl;
}

