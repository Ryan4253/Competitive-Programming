#include<bits/stdc++.h>
using namespace std;

int main(){
    cout << "FUCK" << endl;
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
	int n; cin >> n;
	int a[n];

	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	sort(a, a + n);

	if(a[0] == a[1]){
		cout << a[n-1] << endl;
	}
	else{
		cout << a[0] << endl;
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--){
		solve();
	}
}
