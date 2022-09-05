#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

const int N = 200000 + 5;
int a[N];
int use[N];
int ind[N];
vector<int> v;
set<int> st;

void solve(){
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}


	for(int i = 0; i < n; i++){
		if(i == 0 || a[i] != a[i-1]){
			use[a[i]] = 1;
			ind[i] = 1;
		}	
	}


	for(int i = 1; i <= n; i++){
		if(!use[i]){
			v.pb(i);
			st.insert(i);
		}
	}

	int current = 0;

	for(int i = 0; i < n; i++){
		if(ind[i]){
			cout << a[i] << " ";
		}
		else{
			cout << v[current] << " ";
			current++;
		}
	}

	cout << endl;
	int currentMax = 0;
	for(int i = 0; i < n; i++){
		if(ind[i]){
			cout << a[i] << " ";
			currentMax = a[i];
		}
		else{
			set<int>::iterator it = st.lower_bound(currentMax);
			if (it != st.begin()) {
 				it--;
 			}
 			cout << *it << " ";
 			currentMax = *it;
  			st.erase(*it);
		}
	}	

	cout << endl;

	v.clear();
	for(int i = 0; i < n+5; i++){
		a[i] = 0;
		use[i] = 0;
		ind[i] = 0;
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--){
		solve();
 	}
}
