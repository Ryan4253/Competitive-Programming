#include<bits/stdc++.h>
using namespace std;

//#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second



const int MAXN  = 100000 + 5;
int spf[MAXN]; 
int cnt[MAXN];

void sieve() 
{ 
    spf[1] = 1; 
    for (int i=2; i<MAXN; i++) 
  
    for (int i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
  
    for (int i=3; i*i<MAXN; i++) 
    { 
        if (spf[i] == i) 
        { 
            for (int j=i*i; j<MAXN; j+=i) 

                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 

int edit(int x) 
{ 
    set<int> st;
    while (x != 1) 
    { 
    	if(st.count(spf[x])){
    		st.erase(spf[x]);
    	}
    	else{
    		st.insert(spf[x]); 
    	}
        
        x /= spf[x]; 
    } 

    ll int sol = 1;
   	while(!st.empty()){
   		sol *= *st.begin();
   	}
    return sol; 
} 
  
void solve(){

	int n; cin >> n;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		int y = edit(x);
		cnt[y]++;
		cout << y << " ";
	}
	cout << endl;

	int sol = 0;
	for(int i = 0; i < n; i++){
		sol = max(sol, cnt[i]);
	}

	cout << sol << endl;
	memset(cnt, 0, sizeof(cnt));

}

int main(){
	sieve();
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--){
		solve();
 	}
}
