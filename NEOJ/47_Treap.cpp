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

struct Treap{
    Treap *lc, *rc;
    int key, pri, mx, mn;
    
    Treap(int _key):key(_key), pri(rand()), mx(_key), mn(_key), lc(NULL), rc(NULL){}
};

int getMax(Treap* t){
    if(!t){
        return -100000000000ll;
    }
    
    return t->mx;
}

int getMin(Treap* t){
    if(!t){
        return 10000000000;
    }
    
    return t->mn;
}

void pull(Treap *t){
    if(!t){
        return;
    }
    
    t->mx = max({getMax(t->lc), getMax(t->rc), t->key});
    t->mn = min({getMin(t->lc), getMin(t->rc), t->key});
}

Treap* merge(Treap* a, Treap* b){
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

Treap* head = NULL;

void insert(int n){
    Treap* temp = new Treap(n);
    Treap *lc, *rc;
    
    split(head, n, lc, rc);
    head = merge(lc, temp); head = merge(head, rc);
}

void Delete(int n){
    Treap *lc, *mc, *rc;
    
    split(head, n, lc, rc);
    split(lc, n-1, lc, mc);
    
    lc = merge(lc, mc->lc);
    rc = merge(mc->rc, rc);
    head = merge(lc, rc);
}

void query(int n){
    Treap *lc, *rc;
    split(head, n, lc, rc);
    
    int lMax = getMax(lc);
    int rMin = getMin(rc);
    head = merge(lc, rc);
    
    int lDiff = n - lMax;
    int rDiff = rMin - n;
    
    if(lDiff == rDiff){
        cout << lMax << " " << rMin << endl;
    }
    else if(lDiff > rDiff){
        cout << rMin << endl;
    }
    else{
        cout << lMax << endl;
    }
}

void solve(){
	int n; cin >> n;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        int n; cin >> n;
        if(s == "insert"){
            insert(n);
        }
        else if(s == "query"){
            query(n);
        }
        else{
            Delete(n);
        }
    }
}

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}