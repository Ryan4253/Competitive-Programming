#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

struct Treap{
    Treap *lc, *rc;
    int val, mx, key, prio;
    
    Treap(int v, int _key){
        val = v, key = _key, mx = v, prio = rand();
        lc = NULL, rc = NULL;
    }
};

int Mx(Treap* t){
    if(t == NULL){
        return -2147483648;
    }
    else{
        return t->mx;
    }
}

void pull(Treap* t){
    t->mx = max({t->val, Mx(t->lc), Mx(t->rc)});
}

void split(Treap* t, int k, Treap* &a, Treap* &b){
    if(t == NULL){
        a = b = NULL;
    }
    else if(t->key >= k){
        b = t;
        split(t->lc, k, a, b->lc);
        pull(b);
    }
    else if(t->key < k){
        a = t;
        split(t->rc, k, a->rc, b);
        pull(a);
    }
}

Treap* merge(Treap* a, Treap* b){
    if(!a || !b){
        return a ? a : b;
    }
    if(a->prio >= b->prio){
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

Treap* root = NULL;

void query(int l, int r){
    Treap *left, *right;
    split(root, l, left, root);
    split(root, r+1, root, right);
    cout << root->mx << endl;
    root = merge(left, root);
    root = merge(root, right);
    // root = merge(merge(left, root), right);
}

void solve(){
	int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        root = merge(root, new Treap(x, i+1));
    }
    
    int m; cin >> m;
    for(int i = 0; i < m; i++){
        int l, r; cin >> l >> r;

        query(min(l, r), max(l, r));
    }
    
    
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}