#include<bits/stdc++.h>
using namespace std;
int main(){
	int x; cin >> x;
	
	for(int i = 0; i < x; i++){
		long long int n, k; cin >> n >> k;
		long long int s = k;
		while (k >= n){
			s = s + k / n - ;
			if(s % n != 0){
				k = k % n + k / n;
			}
			else{
				k = n + k / n;
			}
			cout << n << " " << k << " " << s << endl;
		}
		cout << s << endl;
	}
}

