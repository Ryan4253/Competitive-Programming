#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

const int N = 1000000 + 5;
int a[N];
int temp[N];

int invcnt(int l, int r){
	int cnt = 0;
	
	if(l + 1 == r){
		return 0;
	}
	
	int mid = (l + r) / 2;
	cnt += invcnt(l, mid);
	cnt += invcnt(mid, r);
	int ptr = mid; // which number on right side
	
	for(int i = l; i < mid; i++){
		while(ptr < r && a[ptr] < a[i]){
			ptr++;
		}
		cnt += ptr - mid;
	}
	
	int lptr = l, rptr = mid;
	int tempptr = 0;
	while(lptr < mid || rptr < r){
		if(lptr == mid || r != rptr && a[lptr] >= a[rptr]){ // lptr == mid (All used up), r != rptr && a[lptr] > a[rptr] -> r isnt used up and r < l
			temp[tempptr] = a[rptr];
			rptr++;
		}
		else{
			temp[tempptr] = a[lptr];
			lptr++;
		}
		tempptr++;
	}
	
	for(int i = l; i < r; i++){
		a[i] = temp[i-l];
	}
	
	return cnt;
}


void solve(){
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	int solution = invcnt(0, n);
	
	if((3 * n - solution) % 2 == 0){
		cout << "Petr" << endl;
	}
	else{
		cout << "Um_nik" << endl;
	}
	
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}

