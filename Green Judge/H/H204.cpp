#include<iostream>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

void solve(){
	int sol[5];
	int a[5][5];
	for(int i = 0; i < 5; i++){
		sol[i] = 0; 
		for(int j = 0; j < 5; j++){
			cin >> a[i][j];
			sol[i] += a[i][j];
		}
	}
	
	int max = 0, maxcnt = 0;
	for(int i = 0; i < 5; i++){
		if(sol[i] > max){
			maxcnt = 0;
			max = sol[i];
		}
		if(sol[i] == max){
			maxcnt++;
		}
	} 
	cout << maxcnt << endl;
	if(sol[0] == max){
		cout << "Saki" << endl;
	}
	if(sol[1] == max){
		cout << "Megumin" << endl;
	}
	if(sol[2] == max){
		cout << "Rem" << endl;
	}
	if(sol[3] == max){
		cout << "Sagiri" << endl;
	}
	if(sol[4] == max){
		cout << "Kirino" << endl;
	}
	
	
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		solve();
	}
}

