#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back
 
void solve(){
	int n; cin >> n;
	
	stack<int> s;
	int remove = 0;
	int cnt = 0;
	
	for(int i = 0; i < 2 * n; i++){
		string lmao; cin >> lmao;
		if(lmao[0] == 'a'){
			int x; cin >> x;
			s.push(x);
		}
		else{
			remove++;
			if(!s.empty()){
				if(s.top() == remove){
					s.pop();
				}
				else{
					while(!s.empty()){
						s.pop();
					}
					cnt++;
				}
			}
		}
		
	}
	cout << cnt << endl;
}
 
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
}
