#include<bits/stdc++.h>
using namespace std;
void solve(){
	int a, b, c; cin >> c >> b >> a;
	if(a != 0){
		for(int i = 0; i <= a; i++){
			cout << "1"; 
		}
	}
	
	if(a == 0 && b != 0){
		cout << "1" ;
	}
	
	if(b % 2 == 1){
		for(int i = 0; i < b; i++){
			cout << i%2;
		}
	}
	
	if(b % 2 == 0){
 		for(int i = 0; i < b-1; i++){
			cout << i%2;
		}
 	}
 	
	if(b == 0 && c != 0){
		cout << "0";
	}
	
	if(c != 0){
		for(int i = 0; i < c; i++){
			cout << "0"; 
		}
	}
	
	if(b % 2 == 0 && b != 0){
		cout << "1";
	}
	cout << endl;
}

int main(){
	int n = 0; cin >> n;
	for(int i = 0; i < n; i++){
		solve(); 
	}
}

