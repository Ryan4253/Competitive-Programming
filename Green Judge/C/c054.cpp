#include<iostream>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

void solve(){
	int x = 50, y = 50, face = 1;
	int n;
	while(1){
		cin >> n;
		if(n == 0){
			break;
		}
		else if(n == -1){
			face += 3;
			face %= 4;
		}
		else if(n == -2){
			face += 1;
			face %= 4;
		} 
		else if(n == -3){
			face += 2;
			face %= 4;
		}
		else{
			if(face == 0){
				y += n;
				if(y > 100){
					y = 100;
				}
			}
			else if(face == 1){
				x += n;
				if(x > 100){
					x = 100;
				}
			}
			else if(face == 2){
				y -= n;
				if(y < 0){
					y = 0;
				}
			}
			else if(face == 3){
				x -= n;
				if(x < 0){
					x = 0;
				}
			}
		}
	}
	
	cout << "(" << x << "," << y << ")" << endl; 
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}

