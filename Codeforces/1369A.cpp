#include<bits/stdc++.h>
using namespace std;
int main(){
	int n = 0; cin >> n;
	for(int j = 0; j < n; j++){
		int x = 0; cin >> x;
		if(x % 4 == 0){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}
}

