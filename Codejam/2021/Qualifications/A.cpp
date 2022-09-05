#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second


const int N = 1000;
int a[N];
int aa[N];

void solve(){
	int n; cin >> n;
	int a[n], aa[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
		aa[i] = a[i];
	}

	sort(aa, aa + n);
	int sol = 0;
	for(int i = 0; i < n-1; i++){
		for(int j = i; j < n; j++){
			if(a[j] == aa[i]){
				sol += (j-i+1);
				for(int k = i; k <= (j+i)/2; k++){
					swap(a[k], a[j-k+i]);
					//cout << "SWAPPED " << k << "AND " << j-k+i << endl;
				}
				break;
			}
		}
		/*
		for(int l = 0; l < n; l++){
			cout << a[l] << " ";
		}	
		cout << endl;
		*/
	}
	cout << sol << endl;

	memset(a, 0, sizeof(a));
	memset(aa, 0, sizeof(aa));
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for(int i = 1; i <= n; i++){
		cout << "Case #" << i << ": ";
		solve();
	}
	
}
