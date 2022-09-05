#include<bits/stdc++.h>
using namespace std;
int main(){
	int n; cin >> n;
	int a[3][n];
	for(int i = 0; i < n; i++){
		cin >> a[0][i] >> a[1][i] >> a[2][i];
	}

	int x[3];
	
	for (int i = 0; i < 3; i++){
		x[i] = 0;
		for(int j = 0; j < n; j++){
			x[i] += a[i][j];
		}
	}
	
	for(int i = 0; i < 3; i++){
		if(x[i] != 0){
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
}

