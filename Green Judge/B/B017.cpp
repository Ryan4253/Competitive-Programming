#include<bits/stdc++.h>
using namespace std;
int main(){
	string l, w;
	getline(cin, l);
	getline(cin, w);
	
	int x, y;
	x = l.size();
	y = w.size();
	
	if(l.size() >= w.size()){
		while(l.size() != w.size()){
			w = '1' + w;
		}
	}
	else{
		while(w.size() != l.size()){
			l = '1' + l;
		}
	}
	
	
}

