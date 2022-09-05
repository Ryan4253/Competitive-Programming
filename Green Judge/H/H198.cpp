#include<iostream>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

void solve(){
	int a, b; cin >> a >> b;
	
	if(a == 0){
		cout << "Labrador" << endl;
	}
	else if(a < 2 * b + 1){
		cout << "Kitty" << endl;
	}
	else if((a - 2 * b - 1) % (b+1) == 0){
		cout << "Labrador" << endl; 
	}
	else{
		cout << "Kitty" << endl;
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		solve(); 
	}
}

