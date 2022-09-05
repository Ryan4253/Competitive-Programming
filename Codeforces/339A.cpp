#include<bits/stdc++.h>
using namespace std;
int main(){
	string s; cin >> s;
	int a[50];
	int cnt = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] != '+'){
			a[cnt] = s[i] - 48;
			cnt++;
		}
	}
	
	int sol[cnt];
	int max = 0;
	int ptr = 0;
	for(int i = 0; i < cnt; i++){
		for(int j = 0; j < cnt; j++){
			if(a[j] > max){
				max = a[j];
				ptr = j;
			}
		}
		sol[i] = max;
		max = 0;
		a[ptr] = 0;
	}
	cout << sol[cnt-1];
	for(int i = cnt-2; i >= 0; i--){
		cout << "+" << sol[i];
	}
}

