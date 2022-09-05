#include<bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	for(int u = 0; u < t; u++){
		int n = 0; cin >> n;
		if(n <= 3){
			cout << "-1" << endl;
		}
		else if (n%2 == 0){
			for(int i = 1; i <= n - 1; i+=2){
				cout << n - i << " ";
			}
			
			cout << "4" << " " << "2" << " ";
			
			for(int i = 6; i <= n; i+=2){
				cout << i << " ";
			}
			cout << endl;
		}
		else{
			for(int i = 0; i < n ; i+=2){
				cout << n - i << " ";
			}
			
			cout << "4" << " " << "2" << " ";
			
			for(int i = 6; i <= n - 1; i+=2){
				cout << i << " ";
			}
			cout << endl;
		}
	}
}

