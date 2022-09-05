\#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

//void clear(int n){for(int i = 0; i < n; i++){a[i] = 0;}}

vector<int> candidate;

int toNum(string s){
	int val = 0;
	for(int i = 0; i < (int)s.size(); i++){
		val *= 10;
		val += (s[i]-48);
	}
	//cout << val << endl;
	return val;
}

void genCandidate(int start, int size){
	string s = to_string(start);
	while((int)s.size() < size){
		start++;
		s += to_string(start);
	}

	if((int)s.size() == size){
		candidate.pb(toNum(s));
	}
}

void init(){
	
	for(int i = 1; i <= 9; i++){
		genCandidate(i, 2);
	}

	for(int i = 1; i <= 99; i++){
		genCandidate(i, 3);
	}

	for(int i = 1; i <= 99; i++){
		genCandidate(i, 4);
	}

	
	for(int i = 1; i <= 999; i++){
		genCandidate(i, 5);
	}

	for(int i = 1; i <= 999; i++){
		genCandidate(i, 6);
	}

	candidate.pb(1234567);
	/*
	for(int i = 0; i < candidate.size(); i++){
		//cout << candidate[i] << endl;
	}
	*/
	//cout << candidate.size() << endl;
	sort(candidate.begin(), candidate.end());
}


void solve(){
	int n; cin >> n;

	cout << candidate[upper_bound(candidate.begin(), candidate.end(), n)-candidate.begin()] << endl;

}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	init();
	
	for(int i = 1; i <= n; i++){
		cout << "Case #" << i << ": ";
		solve();
	}
}