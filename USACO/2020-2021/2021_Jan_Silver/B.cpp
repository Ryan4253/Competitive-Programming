#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

const int N = 100000 + 5;
stack<int> sta;
int pre[N];
int post[N];
int a[N];

void solve(){
	int n, q; cin >> n >> q;
    string s; cin >> s;
    
    for(int i = 0; i < s.size(); i++){
        a[i] = s[i]-'A'+1;
    }
    
    sta.push(0);
    int size = 0;
    for(int i = 0; i < n; i++){
        while(sta.top() > a[i]){
            sta.pop();
        }
        if(sta.top() == a[i]){
            pre[i] = size;
        }
        else{
            pre[i] = ++size;
        }
        sta.push(a[i]);
    }
    
    reverse(a, a + n);
    size = 0;
    while(!sta.empty()){
        sta.pop();
    }
    sta.push(0);
    
    for(int i = 0; i < n; i++){
        while(sta.top() > a[i]){
            sta.pop();
        }
        if(sta.top() == a[i]){
            post[i] = size;
        }
        else{
            post[i] = ++size;
        }
        sta.push(a[i]);
    }
    
    reverse(post, post + n);
    
    for(int i = 0; i < q; i++){
        int start, end; cin >> start >> end;
        start--, end--;
        
        if(start == 0 && end == n-1){
            cout << 0 << endl;
        }
        else if(start == 0){
            cout << post[end+1] << endl;
        }
        else if(end == n-1){
            cout << pre[start-1] << endl;
        }
        else{
            cout << pre[start-1] + post[end+1] << endl;
        }
        
    }
    /*
    for(int i = 0; i < n; i++){
    	cout << pre[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < n; i++){
    	cout << post[i] << " ";
    }
    cout << endl;
    */
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}