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
int color[N];
Node st[2 * N];
vector<int> v[26];
int st_ptr = 0;

void build(int l, int r, int index){
    st[index].l = l; st[index].r = r;
    if(l + 1 == r){
        st[index].val = color[l];
        return;
    }
    
    int mid = (l + r) / 2;
    
    st[index].lson = ++st_ptr;
    st[index].rson = ++st_ptr;
    
    build(l, mid, st[index].lson);
    build(mid, r, st[index].rson);
    
    st[index].val = max(st[st[index].lson].val, st[st[index].rson].val);
}

void modify(int x, int y, int index){
    if(st[index].l + 1 == st[index].r){
        st[index].val = y;
        return;
    }
    
    int mid = (st[index].l + st[index].r) / 2;
    if(x >= mid){
        modify(x, y, st[index].rson);
    }
    else{
        modify(x, y, st[index].lson);
    }
    
    st[index].val = max(st[st[index].lson].val, st[st[index].rson].val);
}

int query(int l, int r, int index){
    if(st[index].l == l && st[index].r == r){
        return st[index].val;
    }
    int mid = (st[index].l + st[index].r) / 2;
    if(mid <= l){
        return query(l, r, st[index].rson);
    }
    else if(mid >= r){
        return query(l, r, st[index].lson);
    }
    else{
        return max(query(l, mid, st[index].lson), query(mid, r, st[index].rson));
    }
}

void solve(){
	int n; cin >> n;
    string s; cin >> s;
    for(int i = 0; i < n; i++){
        a[i] = s[i] - 97;
    }
    build(0, n, 0);
    
    for(int i = 0; i < n; i++){
        v[a[i]].pb(i);
    }
    
    for(int i = 0; i < 26; i++){
    	for(int j = 0; j < v[i].size(); j++){
    		int r = query(v[i][j], n, 0);
            color[v[i][j]] = ++r;
            modify(v[i][j], color[v[i][j]], 0);
		}
	}
	cout << *max_element(color, color + n) << endl;;
    for(int i = 0; i < n; i++){
        cout << color[i] << " ";
    }
    cout << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n = 1;
	while(n--){
		solve();
 	}
}
