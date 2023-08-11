#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

const int N = 100000 + 5;
int a[N];
int temp[N];

int invpair(int l, int r){
	//part 1, end if there's only 1 element
	if(l + 1 == r){
		return 0;
	}
	
	//part 2, adding sum of inversion pairs from 2 halves
	int sol = 0;
	int mid = (l + r) / 2;
	sol += invpair(0, mid);
	sol += invpair(mid, r);
	
	//part 3, finding inversion pair between the 2 halves. 
	//Note that the 2 halves are pre-sorted already (using merge sort)
	//for loop condition - go through all left side values
	//while loop condition - a[i] > a[ptr] means an inversion pair is present (left > right)
	//if r = ptr, then all right sides are used up, all right side values will form in inv. pair
	int ptr = mid;
	for(int i = l; i < mid; i++){
		while(r > ptr && a[ptr] < a[i]){ 
			ptr++;
		}
		sol += ptr - mid;
	}
	
	//part 4, merge sort into temporary array
	//while loop condition - if any value from left / right isn't sorted, continue sorting
	//sorting condition:
	//1 - if lptr = mid, all left values have been sorted, then just add right to temp
	//2 - if right is smaller than left and right isn't used up, then add right to temp
	//3 - if both conditions above isn't satisfied, then put left values in
	int lptr = l, rptr = mid, tempptr = 0;
	while(lptr < mid || rptr < r){
		if(lptr == mid || rptr != r && a[lptr] > a[rptr]){
			temp[tempptr] = a[rptr];
			rptr++;
		}
		else{
			temp[tempptr] = a[lptr];
			lptr++;
		}
		tempptr++;
	}
	
	//part 5, overwriting a array with sorted temp array
	for(int i = l; i < r; i++){
		a[i] = temp[i-l];
	}
	
	return sol;
}


void solve(){
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	cout << invpair(0, n) << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}

