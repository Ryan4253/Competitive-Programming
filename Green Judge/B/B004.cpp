#include<iostream>
using namespace std;
int main (){
	int n = 0, m = 0, x = 0; cin >> n >> m;
	int a[m];
	for(int i = 0; i < m; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < m; j++){
			if (a[j] == i){
				x = x + 1;
			}
		}
		if (x == 0){
				cout << i << " ";
			}
			x = 0;
	}
}
	
