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
	int n; cin >> n;
    vector<pair<string, string> > p;
    for(int i = 0; i < n; i++){
        string a; cin >> a;
        string t; cin >> t; cin >> t; cin >> t; cin >> t;
        string b; cin >> b;
        p.pb(mp(a, b));
    }
    
    vector<string>v = {"Beatrice", "Sue", "Belinda", "Bessie", "Betsy", "Blue", "Bella", "Buttercup"};
    sort(v.begin(), v.end());
    
    do {
        bool flag = true;
        for(int i = 0; i < p.size(); i++){
            bool indflag = false;
            for(int j = 0; j < 7; j++){
                if((p[i].first == v[j] && p[i].second == v[j+1]) || (p[i].first == v[j+1] && p[i].second == v[j])){
                    indflag = true;
                }
                
            }
            if(!indflag){
                flag = false;;
            }
        }
        
        if(flag){
            for(int i = 0; i < 8; i++){
                cout << v[i] << endl;
            }
            return;
        }
    } while (next_permutation(v.begin(), v.end()));
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	if(fopen("lineup.in", "r")){
	    freopen("lineup.in", "r", stdin);
	    freopen("lineup.out", "w", stdout);
	}
	solve();
}