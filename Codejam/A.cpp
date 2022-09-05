#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

const int N = 30 + 5;
vector<int> v;


//void clear(int n){for(int i = 0; i < n; i++){a[i] = 0;}}

void solve(){
	int n, k; cin >> n >> k;

	for(int i = 0; i < n; i++){
		int temp; cin >> temp;
		v.pb(temp);
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());


	vector<int> gainOne;
	vector<int> gainBoth;

	gainOne.pb(v[0]-1);
	gainOne.pb(k-v[v.size()-1]);
	for(int i = 1; i < v.size(); i++){
		gainOne.pb((v[i]-v[i-1])/2);
		gainBoth.pb(v[i]-v[i-1]-1);
	}

	sort(gainOne.begin(), gainOne.end(), greater<int>());
	sort(gainBoth.begin(), gainBoth.end(), greater<int>());

	for(int i = 0; i < 10; i++){
		gainOne.pb(0);
		gainBoth.pb(0);
	}
	

	if(n == 1){
		cout << (double)(k-1) / k << endl;
	}
	else{
		int sol = max((gainOne[0] + gainOne[1]), gainBoth[0]);
		cout << (double)sol / k << endl;
	}


	

	v.clear();
	/*
	for(int i = 0; i < v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
	*/
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for(int i = 1; i <= n; i++){
		cout << "Case #" << i << ": ";
		solve();
	}

}
