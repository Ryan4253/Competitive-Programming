#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second


void solve(){
	string a, b; cin >> a >> b;
	int maxlength = 0;

	for(int start = 0; start < a.size(); start++){
		for(int end = start; end < a.size(); end++){
			string candidate = a.substr(start, end-start+1);
			if(b.find(candidate) != std::string::npos){
				maxlength = max(maxlength, (int)candidate.size());
			}
		}
	}

	for(int start = 0; start < b.size(); start++){
		for(int end = start; end < b.size(); end++){
			string candidate = b.substr(start, end-start+1);
			if(a.find(candidate) != std::string::npos){
				maxlength = max(maxlength, (int)candidate.size());
			}
		}
	}

	cout << a.size() + b.size() - maxlength * 2 << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--){
		solve();
 	}
}
