#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n, k; cin >> n >> k;
	vector<int> a11;
	vector<int> a10;
	vector<int> a01;
	int t, a, b;
	for(int i = 0; i < n; i++){
		cin >> t >> a >> b;
		if(a == 1 && b == 1){
			a11.push_back(t);
		}
		if(a == 0 && b == 1){
			a01.push_back(t);
		}
		if(a == 1 && b == 0){
			a10.push_back(t);
		}
	}
	
	sort(a11.begin(), a11.end());
	sort(a10.begin(), a10.end());
	sort(a01.begin(), a01.end());
	if(a11.size() + min(a01.size(), a10.size()) < k){
		cout << "-1" << endl;
		return;
	} 
	int mini = 2000000000;

	for(int i = 1; i < a11.size(); i++){
		a11[i] += a11[i-1];
	}
    for(int i = 1; i < a10.size(); i++){
        a10[i] += a10[i-1];
    }
    for(int i = 1; i < a01.size(); i++){
        a01[i] += a01[i-1];
    }
	
	for(int i = a11.size(); i >= 0; i--){
		int tmp = 0;
        if (k - i > min(a01.size(), a10.size())) {
            continue;
        }
        if (i - 1 == -1){
            tmp += 0;
        } 
        else {
            tmp += a11[i - 1];
        }
        if (k - i - 1 == -1){
            tmp += 0;
        } 
        else{
            tmp += a10[k - i - 1];
        }
        if (k - i - 1 == -1) {
            tmp += 0;
        }
        else {
            tmp += a01[k - i - 1];
        }
        if(mini > tmp){
            mini = tmp;
        }
	}
    cout << mini << endl;
    
}

int main(){
	solve();
}
