#include<iostream>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

int a[4];

void solve(){
	string s; cin >> s;
	
	
	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'H'){
			a[0]++; 
		}
		else if(s[i] == 'A'){
			a[1]++;
		}
		else if(s[i] == 'P'){
			a[2]++;
		}
		else if(s[i] == 'Y'){
			a[3]++;
		}
		
		
	}
	a[2] /= 2;
	cout << min(a[0], min(a[1], min(a[2], a[3]))) << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}

