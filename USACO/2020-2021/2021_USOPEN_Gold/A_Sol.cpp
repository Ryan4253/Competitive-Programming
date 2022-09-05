#include<bits/stdc++.h>
using namespace std;

//#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

struct Node{
    int val;
    int l, r;
    int lson, rson;
};

const int N = 200000 + 5;
int a[N];
Node st[2*N];

int st_ptr = 0;

vector<int> v[N];
int Left[N];
int Right[N];

vector<int> lleft[N];
vector<int> rright[N];

void build(int l, int r, int index){
    st[index].l = l; st[index].r = r;
    if(l + 1 == r){
        st[index].val = 0;
        return;
    }
    
    int mid = (l + r) / 2;
    
    st[index].lson = ++st_ptr;
    st[index].rson = ++st_ptr;
    
    build(l, mid, st[index].lson);
    build(mid, r, st[index].rson);
    
    st[index].val = st[st[index].lson].val + st[st[index].rson].val;
}

void modify(int pos, int index){
    if(st[index].l + 1 == st[index].r){
        st[index].val = 1;
        return;
    }
    
    int mid = (st[index].l + st[index].r) / 2;
    if(pos >= mid){
        modify(pos, st[index].rson);
    }
    else{
        modify(pos, st[index].lson);
    }
    
    st[index].val = st[st[index].lson].val + st[st[index].rson].val;
}

int query(int l, int r, int index){   
	//cout << l << " " << r << " " << index << endl;
    if(st[index].l == l && st[index].r == r){
        return st[index].val;
    }
    
    int mid = (st[index].l + st[index].r) / 2;
    if(r <= mid){
        return query(l, r, st[index].lson);
    }
    else if(l >= mid){
        return query(l, r, st[index].rson);
    }
    else{
        return query(l, mid, st[index].lson) + query(mid, r, st[index].rson);
    }
}

void solve(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        v[a[i]].pb(i);
    }
    
    build(0, n, 0);
    //cout << "BUILD" << endl;
    
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < v[i].size(); j++){
        	if(j == 0 && j == v[i].size()-1){
        		Left[v[i][j]] = 0;
        		Right[v[i][j]] = n;
        	}
            else if(j == 0){
                Left[v[i][j]] = 0;
                Right[v[i][j]] = v[i][j+1];
            }
            else if(j == v[i].size()-1){
                Left[v[i][j]] = v[i][j-1];
                Right[v[i][j]] = n;
            }
            else{
                Left[v[i][j]] = v[i][j-1];
                Right[v[i][j]] = v[i][j+1];
            }
        }
    }

    /*
    for(int i = 0; i < n; i++){
    	cout << Left[i] << " ";
    }
    cout << endl;
    */

    for(int i = 0; i < n; i++){
        lleft[Left[i]].pb(i);
        rright[Right[i]].pb(i);
    }
    
    ll int sol = 0;
    for(int i = 0; i < n-1; i++){

        for(int j = 0; j < lleft[i].size(); j++){
            modify(lleft[i][j], 0);
            //cout << lleft[i][j] << endl;
        }
        
        sol += query(i, Right[i], 0)-1;
        //cout << sol << endl;
        //cout << endl;
    }
    
    cout << sol << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}