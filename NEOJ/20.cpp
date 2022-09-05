#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

const int N = 1000000+5;
const int M = 1000+5;	
int group[N];

void solve(int r, int lineno){
		queue<int> que[M];
		queue<int> line;
		cout << "Line #" << lineno << endl;
		for(int i = 1; i <= r; i++){
			int t; cin >> t;
			for(int j = 0; j < t; j++){
				int y; cin >> y;
				group[y] = i;
			}
		}
	
		while(1){
			string s; cin >> s;
			if(s == "ENQUEUE"){
				int n; cin >> n;
				
                if(group[n] == 0){
					
					line.push(-n);
				}
                
				else if(que[(group[n])].empty()){
					que[group[n]].push(n);
					line.push(group[n]);
				}
				
				else{
					que[group[n]].push(n);
				}
			}
			else if(s == "DEQUEUE"){
                if(line.front() < 0){
                    cout << -line.front() << endl;
                    line.pop();
                    continue;
                }
				cout << que[line.front()].front() << endl;
				que[line.front()].pop();
				if(que[line.front()].empty()){
					line.pop();
				}
			}
			else{
				break;
			}
		}
	}	

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int r, lineno = 1;
	while(cin >> r){
		solve(r, lineno);
		lineno++;
		memset(group, 0, sizeof(group));
	}	
}
