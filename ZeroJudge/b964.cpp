#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

const int N = 20 + 5;
int a[N];

void solve(){
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	sort(a, a + n);

	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	cout << endl;

	if(a[0] >= 60){
		cout << "best case" << endl;
	}
	else{
		if(n == 1){
			cout << a[0] << endl;
		}
		else if(a[n-1] < 60){
			cout << a[n-1] << endl;
		}
		for(int i = 0; i < n; i++){
			if(a[i] >= 60){
				cout << a[i-1] << endl;
				break;
			}
		}
	}

	if(a[n-1] < 60){
		cout << "worst case" << endl;
	}
	else{
		for(int i = 0; i < n; i++){
			if(a[i] >= 60){
				cout << a[i] << endl;
				break;
			}
		}
	}


}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
