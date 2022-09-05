#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

const int N = 200000 + 5;
int a[N];

void clear(int len){
	for(int i = 0; i < len; i++){
		a[i] = 0;
	}
}

void solve(){
	int x, y; cin >> x >> y;
	string s; cin >> s;
	for(int i = 0; i < s.size()/2; i++){
		if(s[i] == '0' && s[s.size()-i-1] == '0'){
			x -= 2;
			a[i] = 0, a[s.size()-i-1] = 0;
		}
		else if(s[i] == '1' && s[s.size()-i-1] == '1'){
			y -= 2;
			a[i] = 1, a[s.size()-i-1] = 1;
		}
		else if(s[i] == '0' && s[s.size()-i-1] == '?'){
			x -= 2;
			a[i] = 0, a[s.size()-i-1] = 0;
		}
		else if(s[i] == '?' && s[s.size()-i-1] == '0'){
			x -= 2;
			a[i] = 0, a[s.size()-i-1] = 0;
		}
		else if(s[i] == '1' && s[s.size()-i-1] == '?'){
			y -= 2;
			a[i] = 1, a[s.size()-i-1] = 1;
		}
		else if(s[i] == '?' && s[s.size()-i-1] == '1'){
			y -= 2;
			a[i] = 1, a[s.size()-i-1] = 1;
		}
		else if(s[i] == '?' && s[s.size()-i-1] == '?'){
			a[i] = -1, a[s.size()-i-1] = -1;
		}
		else{
			clear(s.size());
			cout << -1 << endl;
			return;
		}
	}

	if(s.size() % 2 == 1){
		if(s[s.size()/2] == '0'){
			a[s.size()/2] = 0;
			x--;
		}
		else if(s[s.size()/2] == '1'){
			a[s.size()/2] = 1;
			y--;
		}
		else{
			a[s.size()/2] = -1;
		}
	}
	

	for(int i = 0; i < s.size()/2; i++){
		if(a[i] == (-1)){
			if(x >= 2){
				x -= 2;
				a[i] = 0, a[s.size()-i-1] = 0;
			}
			else if(y >= 2){
				y -= 2;
				a[i] = 1, a[s.size()-i-1] = 1;
			}
			else{
				cout << -1 << endl;
				clear(s.size());
				return;
			}
		}
	}

	if(s.size() % 2 == 1 && a[s.size()/2] == -1){
		if(x == 1){
			a[s.size()/2] = 0;
			x--;
		}
		else if(y == 1){
			a[s.size()/2] = 1;
			y--;
		}
		else{
			cout << -1 << endl;
			clear(s.size());
			return;
		}
	}

	if(x != 0 || y != 0){
		cout << -1 << endl;
		clear(s.size());
		return;
	}

	for(int i = 0; i < s.size(); i++){
		cout << a[i];
	}
	cout << endl;

	

	clear(s.size());
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--){
		solve();
	}
}
