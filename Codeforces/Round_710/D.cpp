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
int cnt[N];

void dis(int n){
    vector<int> v;
    for(int i = 0; i < n; i++){
        v.pb(a[i]);
    }
    
    v.resize(unique(v.begin(), v.end())-v.begin());
    
    for(int i = 0; i < n; i++){
        a[i] = lower_bound(v.begin(), v.end(), a[i])-v.begin();
    }
}

void solve(){
	int n; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    sort(a, a + n);
    dis(n);
    /*
    for(int i =0; i< n; i++){
    	cout << a[i] << " ";
    }
    cout << endl;
    */
    for(int i = 0; i < n; i++){
        cnt[a[i]]++;
    }
    
    int mx = 0;
    
    for(int i = 0; i < N; i++){
        mx = max(mx, cnt[i]);
    }
    
    if(mx*2 >= n){
        cout << 2*mx-(n) << endl;
        //cout << mx << endl;
    }
    else{
        if(n % 2 == 0){
            cout << 0 << endl;
        }
        else{
            cout << 1 << endl;
        }
    }

    for(int i = 0; i < n; i++){
    	a[i] = 0;
    }
    for(int i = 0; i < N; i++){
    	cnt[i] = 0;
    }
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    while(n--){
        solve();
    }
}