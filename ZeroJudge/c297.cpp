#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second


queue<int> q;

vector<string> v[10];
int score[30];

void reset(){
	while(!q.empty()){
		q.pop();
	}

	for(int i = 0; i < 3; i++){
		q.push(0);
	}
}

void solve(){
	for(int i = 0; i < 9; i++){
		int n; cin >> n;
		for(int j = 0; j < n; j++){
			string s; cin >> s;
			v[i].pb(s);
		}
	}

	reset();

	int tempscore = 0;
	bool cont = true;
	int out = 0;
	int round = 0;

	while(true){
		for(int i = 0; i < 9; i++){
			if(v[i].empty()){
				cont = false;
				break;
			}
			else{
				if(v[i][0][0] >= 48 && v[i][0][0] <= 57){
					int cnt = v[i][0][0] - '0'-1;
					q.push(1);
					tempscore += q.front();
					q.pop();
					for(int j = 0; j < cnt; j++){
						q.push(0);
						tempscore += q.front();
						q.pop();
					}
				}

				else if(v[i][0] == "HR"){
					q.push(1);
					tempscore += q.front();
					q.pop();
					for(int j = 0; j < 3; j++){
						q.push(0);
						tempscore += q.front();
						q.pop();
					}
				}
				else{
					out++;
					score[out] = tempscore;
					if(out % 3 == 0){
						reset();
					}
				}
				v[i].erase(v[i].begin());
			}
		}

		if(!cont){
			break;
		}
	}

	int q; cin >> q;
	cout << score[q] << endl;
}


int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
