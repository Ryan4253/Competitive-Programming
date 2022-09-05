#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

void solve(){
	
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int h, m, s;
	while(cin >> h && cin >> m && cin >> s){
		if(h * s >= m){
			cout << h << " " << m << " " << s << ". I will make it!" << endl;
		}
		else{
			cout << h << " " << m << " " << s << ". I will be late!" << endl;
		}
	}
}

