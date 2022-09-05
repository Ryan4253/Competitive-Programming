#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

//void clear(int n){for(int i = 0; i < n; i++){a[i] = 0;}}

void solve(){
	int n, k; cin >> n >> k;

	if(n % 2 == 0 && k % 2 == 1){
		if(2 * k > n){
			cout << "NO" << endl;
		}
		else{
			cout << "YES" << endl;
			for(int i = 0; i < k-1; i++){
				cout << 2 << " ";
				n -= 2;
			}
			cout << n << endl;
		}
	}
	else if(n % 2 == 0 && k % 2 == 0){
		if(k > n){
			cout << "NO" << endl;
		}
		else{
			cout << "YES" << endl;
			for(int i = 0; i < k-1; i++){
				cout << 1 << " ";
				n--;
			}
			cout << n << endl;
		}
	}
	else if(n % 2 == 1 && k % 2 == 1){
		if(k > n){
			cout << "NO" << endl;
		}
		else{
			cout << "YES" << endl;
			for(int i = 0; i < k-1; i++){
				cout << 1 << " ";
				n--;
			}
			cout << n << endl;
		}
	}
	else{
		cout << "NO" << endl;
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--){
		solve();
	}
}
