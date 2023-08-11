#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define F first;
#define S second;

const int N = 100000 + 5;

struct Treap{
    int val;
    int sz;
    int mn;
    int pri;
    
    Treap* lc;
    Treap* rc;
    
    int tag;
    bool rev;
    
    Treap(int v){
        val = v;
        sz = 1;
        mn = v;
        pri = rand();
        lc = NULL, rc = NULL;
        tag = 0;
        rev = false;
    }
};

Treap* head = NULL;

int size(Treap* t){
    if(!t){
        return 0;
    }
    return t->sz;
}

int Min(Treap* t){
    if(!t){
        return 2147483647;
    }
    return t->mn + t->tag;
}

void push(Treap* t){
    if(!t){
        return;
    }
    
    if(t->tag != 0){
        t->val += t->tag;
        t->mn += t->tag;
        if(t->lc){
            t->lc->tag += t->tag;
        }
        if(t->rc){
            t->rc->tag += t->tag;
        }
        t->tag = 0;
    }
    
    if(t->rev){
        swap(t->lc, t->rc);
        if(t->lc){
            t->lc->rev ^= 1;
        }
        if(t->rc){
            t->rc->rev ^= 1;
        }
        t->rev = false;
    }
}

void pull(Treap* t){
    t->mn = min(min(Min(t->lc), Min(t->rc)), t->val + t->tag);
    t->sz = size(t->lc) + size(t->rc) + 1;
}

void split(Treap* t, int k, Treap*& a, Treap*& b){
    if(!t){
        a = b = NULL;
        return;
    }
    push(t);
    // if (size(t->lc) + 1 <= sz)
    if(size(t->lc) + 1 <= k){
        a = t;
        split(t->rc, k-size(t->lc) - 1, a->rc, b);
        pull(a);
    }
    else{
        b = t;
        split(t->lc, k, a, b->lc);
        pull(b);
    }
}

Treap* merge(Treap* a, Treap* b){
    if (!a || !b) return a ? a : b;
    
    push(a); push(b);
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

void dfs(Treap* t){
    if(!t){
        return;
    }
    push(t);
    dfs(t->lc);
    cout << t->val + t->tag << " ";
    dfs(t->rc);
}

void add(int start, int end, int val){
    Treap* left; split(head, start-1, left, head);
    Treap* mid; split(head, end-start+1, mid, head);
    mid->tag += val;
    left = merge(left, mid);
    head = merge(left, head);
}

void reverse(int start, int end){
    Treap* left; split(head, start-1, left, head);
    Treap* mid; split(head, end-start+1, mid, head);
    mid->rev ^= 1;
    left = merge(left, mid);
    head = merge(left, head);
}

void revolve(int start, int end, int t){
    t %= (end-start+1);
    t = (t + (end - start + 1)) % (end - start + 1);
    t = (end-start+1) - t; // left size
    Treap* left; split(head, start-1, left, head);
    Treap* mid; split(head, end-start+1, mid, head);
    Treap* rot; split(mid, t, rot, mid);
    left = merge(left, mid);
    head = merge(rot, head);
    head = merge(left, head);
}

void insert(int x, int p){
    Treap* t = new Treap(p);
    Treap* l; split(head, x, l, head);
    l = merge(l, t);
    head = merge(l, head);
}

void del(int x){
    Treap* left; split(head, x-1, left, head);
    Treap* mid; split(head, 1, mid, head);
    head = merge(left, head);
}

int getMin(int start, int end){
    Treap* left; split(head, start-1, left, head);
    Treap* mid; split(head, end-start+1, mid, head);
    //dfs(mid);
    ll int sol = Min(mid);
    left = merge(left, mid);
    head = merge(left, head);
    
    return sol;
}

void solve(){
     int n; cin >> n;
     for(int i = 0; i < n; i++){
         int val; cin >> val;
         Treap* t = new Treap(val);
         head = merge(head, t);
     }
     
     int x; cin >> x;
     for(int i = 0; i < x; i++){
         string s; cin >> s;
         int first, second, third;
         if(s == "ADD"){
             cin >> first >> second >> third;
             add(first, second, third);
         }
         else if(s == "REVERSE"){
             cin >> first >> second;
             reverse(first, second);
         }
         else if(s == "REVOLVE"){
             cin >> first >> second >> third;
             revolve(first, second, third);
         }
         else if(s == "INSERT"){
             cin >> first >> second;
             insert(first, second);
         }
         else if(s == "DELETE"){
             cin >> first;
             del(first);
         }
         else{
             cin >> first >> second;
             cout << getMin(first, second) << endl;;
         }
     }
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n = 1; ;
  while(n--){
    solve();
  }
}
