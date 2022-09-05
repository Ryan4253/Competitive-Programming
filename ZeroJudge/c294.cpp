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
	int a[3];
	for(int i = 0; i < 3; i++){
		cin >> a[i];
	}

	sort(a, a + 3);
	cout << a[0] << " " << a[1] << " " << a[2] << endl;

	if(a[0] + a[1] <= a[2]){
		cout << "No" << endl;
	}
	else{
		if(a[0] * a[0] + a[1] * a[1] == a[2] * a[2]){
			cout << "Right" << endl;
		}
		else if(a[0] * a[0] + a[1] * a[1] > a[2] * a[2]){
			cout << "Acute" << endl;
		}
		else{
			cout << "Obtuse" << endl;
		}
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
