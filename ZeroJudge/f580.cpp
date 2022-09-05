#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

struct dice{
	int top, front, left;

	void init(){
		top = 1;
		front = 4;
		left = 5;
	}
	void forward(){
		int temp = top;
		top = 7-front;
		front = temp;
	}
	void right(){
		int temp = top;
		top = left;
		left = 7-temp;
	}
};

const int N = 20 + 5;
dice a[N];

void swap(int x, int y){
	dice temp = a[x];
	a[x] = a[y];
	a[y] = temp;
}

void solve(){
	int n; cin >> n;
	for(int i = 1; i <= n; i++){
		a[i].init();
	}

	int m; cin >> m;

	for(int i = 0; i < m; i++){
		int aa, b; cin >> aa >> b;
		if(b == -1){
			a[aa].forward();
		}
		else if(b == -2){
			a[aa].right();
		}
		else{
			swap(aa, b);
		}
	}

	for(int i = 1; i <= n; i++){
		cout << a[i].top << " ";
	}
	cout << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
