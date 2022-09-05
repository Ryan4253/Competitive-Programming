#include<iostream>
using namespace std;
int main(){
	int n; cin >> n;
	int cnt = 1;
	while(n >= 3){
		if(n%3 == 0){
			n = n / 3;
		}
		else if (n%3 == 1){
			n = 2 * n + 1;
		}
		else{
			n = 2 * n - 1;
		}
		cnt ++;
	}
	
	cout << cnt << endl;
}

