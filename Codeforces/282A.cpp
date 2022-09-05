#include<bits/stdc++.h>
using namespace std;
int solution = 0;

void solve(){
	string s; cin >> s;
	if(s[1] == '+'){
		solution++;
	}
	else{
		solution--;
	}
}

int main(){
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		solve();
	}
	cout << solution << endl;
}

