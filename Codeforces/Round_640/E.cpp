#include<bits/stdc++.h>
using namespace std;

void output(int n, int x){
	for(int i = 0; i < n; i++){
		cout << x;
	}
}

void zeroone(int a, int b, int c){
	int cnt = 1;
	if(a != 0 || c != 0){
		for(int i = 0; i < b-1; i++){
		cout << cnt%2;
		cnt ++;
		}
	}
	else{
		for(int i = 0; i < b + 1; i++){
		cout << cnt%2;
		cnt ++;
		}
	}
}

int main(){
	int t = 0; cin >> t;
	int a, b, c;
	for(int i = 0; i < t; i++){
		cin >> a >> b >> c;
		if(c != 0){
			output(c+1, 1);
		}
		if(a != 0){
			output(a+1, 0);
		}
		zeroone(a, b, c);
		cout << endl;
	}
}

