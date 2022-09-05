#include<iostream>
#include<vector>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

vector<char> v1;
vector<char> v2;

int move1(){
	int ycnt = 0;
	int weight = 0;

	for(int i = 0; i < (int)v1.size(); i++){
		if(v1[i] == 'Y'){
			weight += (i-ycnt);
			ycnt++;
		}
	}

	int wcnt = 0;

	for(int i = 0; i < (int)v2.size(); i++){
		if(v2[i] == 'W'){
			weight += (ycnt + i - wcnt);
			wcnt++;
		}
	}
	
	return weight;
}

int move2(){
	int wcnt = 0;
	int weight = 0;

	for(int i = 0; i < (int)v1.size(); i++){
		if(v1[i] == 'W'){
			weight += (i-wcnt);
			wcnt++;
		}
	}

	int ycnt = 0;

	for(int i = 0; i < (int)v2.size(); i++){
		if(v2[i] == 'Y'){
			weight += (wcnt + i - ycnt);
			ycnt++;
		}
	}
	
	return weight;
}

void solve(){
	string a, b; cin >> a >> b;
	
	//y == 1, w == -1
	for(int i = 0; i < (int)a.size(); i++){
		v1.pb(a[i]);
	}

	for(int i = 0; i < (int)b.size(); i++){
		v2.pb(b[i]);
	}

	int sol1 = move1();
	int sol2 = move2();

	cout << min(sol1, sol2) << endl;
	v1.clear();
	v2.clear();
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--){
		solve();
 	}
}
