#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

void solve(){
	int n; cin >> n; n--;
	int cnt = 0;
	cout << "I hate ";
	
	while(n--){
		if(cnt % 2 == 0){
			cout << "that I love ";
		}
		else{
			cout << "that I hate ";
		}
		cnt++;
	}
	
	cout << "it" << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}

