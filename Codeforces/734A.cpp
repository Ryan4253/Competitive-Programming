#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long;
#define pii paid<int, int>


void solve(){
	int n; cin >> n;
	string s; cin >> s;
	int d = 0, a = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'D'){
			d++;
		}
		else{
			a++;
		}
	}
	
	if(a > d){
		cout << "Anton" << endl;
	}
	else if(d > a){
		cout << "Danik" << endl;
	}
	else{
		cout << "Friendship" << endl;
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n = 1;
	while(n--){
		solve();
 	}
}

