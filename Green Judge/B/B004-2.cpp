#include<iostream>
using namespace std;
int main(){
	int n = 0, m = 0, x = 0; cin >> n >> m;
	int a[n+1];
	
	for (int i = 1; i <= n; i++){
		a[i] = 0;
		}
		
	for(int i = 1; i <= m; i++){
		cin >> x;
		a[x] = 1;
	}
	
	for (int i = 1; i <= n; i++){
		if(a[i] == 0){
			cout << i << " ";
		}
	}
		
}
