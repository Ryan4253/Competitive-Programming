#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

bool check(string s, int n){
    vector<string> v;
    for(int i = 0; i <= s.length()-n; i++){
        v.pb(s.substr(i, n));
    }
    
    sort(v.begin(), v.end());
    
    for(int i = 0; i < v.size()-1; i++){
        if(v[i] == v[i+1]){
            return false;
        }
    }
    
    return true;
}

void solve(){
	int n; cin >> n;
    string s; cin >> s;
    
    for(int i = 1; i <= n; i++){
        if(check(s, i)){
            cout << i << endl;
            return;
        }
    }
    
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	if(fopen("whereami.in", "r")){
	    freopen("whereami.in", "r", stdin);
	    freopen("whereami.out", "w", stdout);
	}
	solve();
}