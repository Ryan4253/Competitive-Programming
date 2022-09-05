	#include<bits/stdc++.h>
	using namespace std;
	int main(){
		int n, m; cin >> n >> m;
		int a[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		
		int sol = 0;
		
		for(int i = 0; i < n; i++){
			if(a[i] >= a[m - 1] && a[i] > 0){
				sol++;
			}
		}
		
		cout << sol << endl;
	}

