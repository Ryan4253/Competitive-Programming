#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second


void solve(){
	int score[4];
	int a[4];
	for(int i = 0; i < 4; i++){
		cin >> a[0] >> a[1] >> a[2] >> a[3];
		score[i] = accumulate(a, a + 4, 0);
	}

	cout << score[0] << ":" << score[1] << endl;
	cout << score[2] << ":" << score[3] << endl;

	int winhome = 0;
	int winaway = 0;
	if(score[0] == score[1]){
		winhome++;
		winaway++;
	}
	else if(score[0] > score[1]){
		winhome++;
	}
	else{
		winaway++;
	}

	if(score[2] == score[3]){
		winhome++;
		winaway++;
	}
	else if(score[2] > score[3]){
		winhome++;
	}
	else{
		winaway++;
	}

	if(winhome > winaway){
		cout << "Win" << endl;
	}
	else if(winaway > winhome){
		cout << "Lose" << endl;
	}
	else{
		cout << "Tie" << endl;
	}

}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
