#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

const int N = 100000 + 5;
int a[N];


void solve(int n, int x){
	int l = 0;
	int r = n;
	if(x < a[0]){
		cout << "0" << endl;
		return;
	}
	else if(x > a[n-1]){
		cout << n << endl;
		return;
	}
	
	while(l + 1 != r){
		int mid = (l + r) / 2;
		if(x >= a[mid]){
			l = mid;
		}
		else{
			r = mid;
		}
	}
	
	cout << r << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a, a + n);
	int r; cin >> r; 
	int x;
	for(int i = 0; i < r; i++){
		cin >> x;
		solve(n, x);
	}
}


