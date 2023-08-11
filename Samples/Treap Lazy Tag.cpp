#include<bits/stdc++.h>
using namespace std;

#define ll long long
//#define endl '\n'
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define F first;
#define S second;

const int N = 100000 + 5;
int a[N];

struct Treap{
    int val, pri;
    Treap* lc, *rc;
    int mx;
    int tag;
    int key;
    Treap(int _key){
        key = _key;
        val = a[key];
        pri = rand();
        mx = val;
        lc = rc = NULL;
        tag = 0;
    }
};

int mx(Treap* t){
    if(t == NULL){
        return 0;
    }
    else{
        return t->mx + t->tag;
    }
}

void push(Treap* t){
    if(t == NULL){
        return;
    }
    
    t->val += t->tag;
    t->mx += t->tag;
    if(t->lc){
        (t->lc)->tag += t->tag;
    }
    if(t->rc){
        (t->rc)->tag += t->tag;
    }
    t->tag = 0;
}

void pull(Treap* t){
    if(!t->lc && !t->rc){
        t->mx = t->val;
        return;
    }
    
    t->mx = max({t->val, mx(t->lc), mx(t->rc)});
}

Treap* merge(Treap* l, Treap* r){
    //cout << "MERGE" << endl;
    push(l); push(r);
    if(!l){
        return r;
    }
    else if(!r){
        return l;
    }
    else{
        if(l->pri > r->pri){
            l->rc = merge(l->rc, r);
            pull(l);
            return l;
        }
        else{
            r->lc = merge(l, r->lc);
            pull(r);
            return r;
        }
    }
    
}

void split(Treap* t, int k, Treap* &l, Treap* &r){
    //cout << "SPLIT" << endl;
    if(!t){
        l = r = NULL;
        return;
    }
    
    push(t);
    
    if(t->key > k){
        r = t;
        split(t->lc, k, l, r->lc);
        pull(r);
    }
    else{
        l = t;
        split(t->rc, k, l->rc, r);
        pull(l);
    }
}

Treap* head = NULL;

void solve(){
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    
    for(int i = 1; i <= n; i++){
        Treap* temp = new Treap(i);
        head = merge(head, temp);
    }
    
    for(int i = 0; i < q; i++){
        int t, l, r; cin >> t >> l >> r;
        if(t == 1){
            int x; cin >> x;
            Treap* left, *right;
            split(head, l-1, left, head);
            split(head, r, head, right);
            head->tag += x;
            head = merge(left, head);
            head = merge(head, right);
        }
        else{
            Treap* left, *right;
            split(head, l-1, left, head);
            split(head, r, head, right);
            cout << mx(head) << endl;
            head = merge(left, head);
            head = merge(head, right);
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