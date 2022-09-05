#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

void solve(){
	int year = 90, month = 7;
	int n; cin >> n;
	while(n > 12){
		year++;
		n -= 12;
	}
	
	month += n;
	if(month > 12){
		month %= 12;
		year++;
	}
	
	cout << year << " " << month << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}

