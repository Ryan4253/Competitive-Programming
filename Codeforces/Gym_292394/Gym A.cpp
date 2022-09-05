#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

const int N = 300000;


void solve(){
	// I lead a life of crime
	vector<pair<int, int> > bigboi;
	vector<pair<int, int> > smolboi;
	
	int n; cin >> n;
	int temp1, temp2;
	int bigsize = 1, smallsize = 1;
	
	for(int i = 1; i <= n; i++){
		cin >> temp1 >> temp2;
		
		if(temp1 > temp2){
			bigboi.pb(make_pair(temp1, i));
			bigsize++;
		}
		else{
			smolboi.pb(make_pair(temp1, i));
			smallsize++;
		}
	}
	
	sort(smolboi.begin(), smolboi.end());
	sort(bigboi.begin(), bigboi.end());
	reverse(smolboi.begin(), smolboi.end());
	
	if(bigsize > smallsize){
		cout << bigboi.size() << endl;
		for(int i = 0; i < bigboi.size(); i++){
			cout << bigboi[i].second << " ";
		}
	}
	else{
		cout << smolboi.size() << endl;
		for(int i = 0; i < smolboi.size(); i++){
			cout << smolboi[i].second << " ";
		}
	}
	
	cout << endl;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}

