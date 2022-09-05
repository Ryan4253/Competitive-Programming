#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

const int N = 500 + 5;
int used[N];

void clear(int n){
	for(int i = 0; i <= n; i++){
		used[i] = 0;
	}
}

int maxUnused(int n){
	for(int i = n; i > 0; i--){
		if(!used[i]){
			return i;
		}
	}
	return 0;
}

int minUnused(int n){
	for(int i = 1; i <= n; i++){
		if(!used[i]){
			return i;
		}
	}
	return 0;
}

void solve(){
	int n, l, r, s; cin >> n >> l >> r >> s;
	int cnt = r-l+1;
	vector<int> v;
	int minsum = 0;
	int maxsum = 0;
	int sum = 0;
	l--; r--;

	for(int i = 1; i <= cnt; i++){
		v.pb(i);
		minsum += i;
		maxsum += (n-1+1);
		sum += i;
		used[i] = true;
	}	
	/*
	for(int i = 0; i < v.size(); i++){
		cout << v[i] << endl;
	}
	*/

	if(minsum > s || maxsum < s){
		cout << -1 << endl;
		clear(n);
		return;
	}

	for(int i = v.size()-1; i >= 0; i--){
		if(sum == s){
			break;
		}
		else{
			int dist = s - sum;
			if(dist > (maxUnused(n)-v[i])){
				sum -= v[i];
				used[v[i]] = false;
				v[i] = maxUnused(n);
				sum += v[i];
				used[v[i]] = true;
			}
			else{
				sum -= v[i];
				used[v[i]] = false;
				v[i] = s-sum;
				sum += v[i];
				used[v[i]] = true;
			}
		}
	}
	/*
	for(int i = 0; i < v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
	*/
	int a[n];

	for(int i = l; i <= r; i++){
		a[i] = v[i-l];
	}

	for(int i = 0; i < n; i++){
		if(i < l || i > r){
			a[i] = minUnused(n);
			used[a[i]] = true;
		}
	}

	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	cout << endl;

	clear(n);



}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--){
		solve();
	}
}
