#include<bits/stdc++.h>
using namespace std;
int main(){
	int t = 0; cin >> t;
	for(int i = 1; i <= t; i++){
		int n = 0, k = 0; cin >> n >> k;
		int end = 0; int solution = k;
		
		while(k / n - end / n != 0){
			solution += k / n - end / n;
			end = k;
			k = solution;
			
			//cout << k << " " << end << " " << solution << endl;
		}
		cout << solution << endl;
	}

}

