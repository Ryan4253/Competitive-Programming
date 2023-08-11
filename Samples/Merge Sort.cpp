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

const int N = 200000 + 5;
int a[N];
int temp[N];

void mergesort(int s, int e){
	if(s + 1 == e){
		return;
	}

	int mid = (s + e) / 2;
	mergesort(s, mid);
	mergesort(mid, e);

	int lptr = s, rptr = mid;

	for(int i = s; i < e; i++){
		if((lptr < mid && a[lptr] <= a[rptr]) || rptr >= e){
			temp[i] = a[lptr];
			lptr++;
		}
		else{
			temp[i] = a[rptr];
			rptr++;
		}
	}

	for(int i = s; i < e; i++){
		a[i] = temp[i];
	}
	/*
	for(int i =0; i < 5; i++){
		cout << a[i] << " ";
	}
	cout << endl;
	*/
}

void solve(){
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	mergesort(0, n);

	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
