#include<iostream>
using namespace std;
int main(){
	int n, k; cin >> n >> k;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	int place = 1;
	for(int i = 0; i < n; i++){
		if(a[i] > a[k-1]){
			place++;
		}
	}
	cout << place << endl;	
}

