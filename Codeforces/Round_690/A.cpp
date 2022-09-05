#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

const int N = 305;
int a[N];

void solve(){
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	int lptr = 0; int rptr = n-1;
	for(int i = 0; i < n; i++){
		if(i % 2 == 0){
			cout << a[lptr] << " ";
			lptr++;
		}
		else{
			cout << a[rptr] << " ";
			rptr--;
		}
	}

	cout << endl;
	memset(a, 0, sizeof(a));
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--){
		solve();
 	}
}
