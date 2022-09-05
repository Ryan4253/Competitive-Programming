#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

const ll int X = 1ll*10000000000;
const ll int XX = 1e10;
const ll int XXX = (1ll << 40);

void solve(){
    multiset<ll int> st;
    int n; cin >> n;
    st.insert(X);
    st.insert(-X);
    
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        int r; cin  >> r;
        if(s[0] == 'i'){
            st.insert(r);
        }
        else if(s[0] == 'q'){
            ll int top = *st.lower_bound(r);
            ll int bottom = *prev(st.lower_bound(r));
            ll int topdiff = top - r;
            ll int bottomdiff = r - bottom;
            
            if(topdiff > bottomdiff){
                cout << bottom << endl;
            }
            else if(bottomdiff > topdiff){
                cout << top << endl;
            }
            else{
                cout << bottom << " " << top << endl;
            }
        }
        else{
            st.erase(st.find(r));
        }
    }
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n = 1;
	while(n--){
		solve();
 	}
}
