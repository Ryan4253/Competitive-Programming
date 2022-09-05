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
	int n, k; cin >> n >> k;
	string s; cin >> s;

	for(int t = 0; t < k; t++){
		for(int i = 0; i < s.size()-1; i++){
			if(s[i] == 'B' && s[i+1] == 'G'){
				swap(s[i], s[i+1]);
				i++;
			}
		}
	}

	cout << s << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
