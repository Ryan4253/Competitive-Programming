 #include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

const int N = 500000 + 5;
int a[N];

struct Treap{
    int val, size, mx, pri;
    Treap *lc, *rc;
    
    Treap(int v){
        val = v, mx = v;
        size = 1;
        pri = rand();
        lc = NULL; rc = NULL;
    }
};

Treap* root = NULL;

int sz(Treap* t){
    if(!t) return 0;
    return t->size;
}

int Max(Treap* t){
    if(!t) return 0;
    return t->mx;
}

void pull(Treap* t){
    if(!t) return;
    t->size = sz(t->lc) + sz(t->rc) + 1;
    t->mx = max({t->val, Max(t->lc), Max(t->rc)});
}

Treap* merge(Treap *a, Treap *b){
    if(!a || !b){
        return !a ? b : a;
    }
    else if(a->pri > b->pri){
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

void splitBySize(Treap* t, int k, Treap* &a, Treap* &b){
    if(!t){
        a = NULL, b = NULL;
    }
    else if(sz(t->lc)+1 <= k){
        a = t;
        splitBySize(t->rc, k-sz(t->lc)-1, a->rc, b);
        pull(a);
    }
    else{
        b = t;
        splitBySize(t->lc, k, a, b->lc);
        pull(b);
    }
}

void solve(){
	int a, b; cin >> a >> b;
    if(a > b){
        swap(a, b);
    }
    Treap* left, *right;
    splitBySize(root, a-1, left, root);
    splitBySize(root, b-a+1, root, right);
    
    cout << Max(root) << endl;
    root = merge(left, root);
    root = merge(root, right);
    
    
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    //cout << "PREINIT" << endl;;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        Treap* temp = new Treap(a[i]);
        root = merge(root, temp);
    }

    //cout << "INITDONE" << endl;
        
    int m; cin >> m;
    while(m--){
    	solve();
    }
}
