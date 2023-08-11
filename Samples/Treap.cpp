#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

//void clear(int n){for(int i = 0; i < n; i++){a[i] = 0;}}

struct Treap{
    int val, pri;
    Treap *lc, *rc;
    int sz;
    int mx;
    
    Treap(int key){
        val = key, pri = rand(), lc = NULL, rc = NULL, sz = 1;
        mx = val;
    }
};

int size(Treap* t){
    if(t == NULL){
        return 0;
    }
    else{
        return t->sz;
    }
}

int _max(Treap* t){
    if(t == NULL){
        return 0;
    }
    else{
        return t->mx;
    }
}

void pull(Treap* t){
    if(!t->lc && !t->rc){
        t->sz = 1;
        t->mx = t->val;
        return;
    }
    
    t->sz = size(t->lc) + size(t->rc) + 1;
    t->mx = max({_max(t->lc), _max(t->rc), t->val}); 
}

Treap* merge(Treap* a, Treap* b){
    if(!a){
        return b;
    }
    else if(!b){
        return a;
    }
    else{
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
}

void split_by_size(Treap* t, int n, Treap* &a, Treap* &b){
    if(!t){
        a = b = NULL;
        return;
    }
    
    if(size(t->lc) < n){
        a = t;
        split_by_size(t->rc, n-size(t->lc)-1, a->rc, b);
        pull(a);
    }
    else{
        b = t;
        split_by_size(t->lc, n, a, b->lc);
        pull(b);
    }
}

const int N = 500000 + 5;
int a[N];

Treap* head = NULL;

void solve(){
	int n; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    	

    for(int i = 0; i < n; i++){
        Treap* temp = new Treap(a[i]);
        head = merge(head, temp);
    }
    int m; cin >> m;
    for(int i = 0; i < m; i++){
        int s, e; cin >> s >> e;
        if(s > e){
        	swap(s, e);
        }
        Treap *left, *right;
        split_by_size(head, s-1, left, head);
        split_by_size(head, e-s+1, head, right);
        
        cout << _max(head) << endl;
        head = merge(left, head);
        head = merge(head, right);
    }
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}