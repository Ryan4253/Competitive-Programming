#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define F first;
#define S second;

vector<int> binaryStringToVector(string s){
	vector<int> ret;
	for(int i = 0; i < s.size(); i++){
	  ret.pb(s[i]-'0');
	}

	return ret;
}

void solve(){
	int n; cin >> n;
	string s; cin >> s;

	vector<int> v = binaryStringToVector(s);

	int zero = 0;
	for(int i = 0; i < v.size(); i++){
		zero += (v[i] == 0);
	}

	if(zero == 1){
		cout << "BOB" << endl;
		return;
	}

	zero % 2 == 0 ? cout << "BOB" << endl : cout << "ALICE" << endl;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  while(n--){
	  solve();
  }
}


