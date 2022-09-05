#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

int value(string s){
	if(s == "Icosahedron"){
		return 20;
	}
	else if(s == "Dodecahedron"){
		return 12;
	}
	else if(s == "Octahedron"){
		return 8;
	}
	else if(s == "Cube"){
		return 6;
	}
	else{
		return 4;
	}
}

void solve(){
	int n; cin >> n;
	int sol = 0;

	for(int i = 0; i < n; i++){
		string s; cin >> s;
		sol += value(s);
	}

	cout << sol << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
