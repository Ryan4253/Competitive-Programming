#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

const int N = 1000000 + 5;
int a[N];

void solve(){
	int n; cin >> n;
	int index = 1;
	int temp;
	for(int i = 1; i <= n; i++){
		cin >> temp;
		int tempindex = index;
		for(int j = tempindex; j < tempindex + temp; j++){
			a[j] = i;
			index++;
		}
	}
	
	int x; cin >> x;
	for(int i = 0; i < x; i++){
		cin >> temp;
		cout << a[temp] << endl;
	}
	
	
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}

