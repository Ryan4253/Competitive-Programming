#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second
#define int ll

//void clear(int n){for(int i = 0; i < n; i++){a[i] = 0;}}

const int N = 200000 + 5;
int a[N];
int pre[N];

struct Treap{
    Treap *lc, *rc;
    int key, pri, sz;
    Treap(int _key): lc(NULL), rc(NULL), key(_key), pri(rand()), sz(1){}
};

int sz(Treap* t){
    return t ? t->sz : 0;
}

void pull(Treap* t){
    if(!t){
        return;
    }
    
    t->sz = sz(t->lc) + sz(t->rc) + 1;
}

Treap* merge(Treap* a, Treap *b){
    if(!a || !b){
        return a ? a : b;
    }
    
    if(a->pri > b->pri){
        a->rc = merge(a->rc, b);
        pull(a);
        return a;
    }
    else{
        b->lc = merge(a, b->lc);
        pull(b);
        return b;
    }
}

void split(Treap* t, int k, Treap* &a, Treap* &b){
    if(!t){
        a = b = NULL;
        return;
    }
    
    if(t->key <= k){
        a = t;
        split(t->rc, k, a->rc, b);
        pull(a);
    }
    else{
        b = t;
        split(t->lc, k, a, b->lc);
        pull(b);
    }
}


void solve(){
	int n, t; cin >> n >> t;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    pre[0] = 0;
    for(int i = 1; i <= n; i++){
        pre[i] = a[i-1] + pre[i-1];
    }
    
    Treap* head = NULL;
    int sol = 0;
    
    for(int i = 1; i <= n; i++){
        Treap* temp = new Treap(pre[i-1]);
        Treap *tl, *tr;
        split(head, pre[i-1], tl, tr);
        head = merge(tl, temp); head = merge(head, tr);
        
        split(head, pre[i]-t, tl, tr);
        sol += sz(tr);
        head = merge(tl, tr);
    }
    
    cout << sol << endl;
}

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}