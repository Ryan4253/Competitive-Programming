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

	int start = -1, end = 0;

	for(int i = 0; i < n; i++){
		if(start == -1 && s[i] == '*'){
			start = i;	
		}
		if(s[i] == '*'){
			end = i;
		}
	}
	int sol;
	if(start == end){
		sol = 1;
	}
	else{
		sol = 2;
	}

	for(int i = start; i < end;){
		for(int j = k; j > 0; j--){
			if(i + j >= n){
				continue;
			}
			if(s[i+j] == '*'){
				if(i+j == end){
					i = i+j-1	;
					break;
				}
				//cout << i + j << endl;
				sol++;
				i = i+j-1;
				break;
			}
		}
		i++;
	}

	cout << sol << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--){
		solve();
	}
}
