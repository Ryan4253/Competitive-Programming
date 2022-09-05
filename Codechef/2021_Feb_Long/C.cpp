#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

int timeToInt(string s1, string s2){
	int hr = ((s1[0]-'0')*10 + (s1[1]-'0')) % 12;
	int min = (s1[3]-'0')*10 + (s1[4]-'0');

	int total = hr * 60 + min;
	if(s2[0] == 'P'){
		total += 720;
	}

	//cout << hr << " " << min << " " << total << endl;
	return total;
}

void solve(){

	string s1, s2; cin >> s1 >> s2;
	int time = timeToInt(s1, s2);
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		string l1, l2, r1, r2; cin >> l1 >> l2 >> r1 >> r2;
		int lbound = timeToInt(l1, l2), rbound = timeToInt(r1, r2);
		if(time >= lbound && time <= rbound){
			cout << 1;
		}
		else{
			cout << 0;
		}
	}

	cout << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--){
		solve();
 	}
}
