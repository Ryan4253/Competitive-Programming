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

void clear(int n){
	for(int i = 0; i < n; i++){
		a[i] = 0;
	}
}

void solve(){
	int n; cin >> n;
	n += 2;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	sort(a, a + n);

	ll int sum = 0;
	for(int i = 0; i < n; i++){
		sum += a[i];
	}

	ll int searchVal = (sum - 2 * a[n-1]);

	for(int i = 0; i < n-1; i++){
		if(a[i] == searchVal){
			for(int j = 0; j < n-1; j++){
				if(j != i){
					//cout <<"HI" << endl;
					cout << a[j] << " ";
				}
			}
			cout << endl;
			clear(n);
			return;
		}
	}

	if(sum - a[n-1] - a[n-2] == a[n-2]){
		for(int i = 0; i < n-2; i++){
			cout << a[i] << " ";
		}
		cout << endl;
		clear(n);
		return;
	}

	cout << -1 << endl;
	clear(n);


}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--){
		solve();
 	}
}
