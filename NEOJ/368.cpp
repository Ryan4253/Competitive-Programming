#include<bits/stdc++.h>
using namespace std;

#define ll long long
//#define endl '\n'
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define F first;
#define S second;

struct Node{
    int val;
    int l, r;
    int lson, rson;
    int aTag, bTag;
};

const int N = 100000 + 5;
int a[N];
Node st[2 * N];
int st_ptr = 0;

void build(int l, int r, int index){
    st[index].l = l; st[index].r = r;
    if(l + 1 == r){
        st[index].val = a[l];
        return;
    }

    int mid = (st[index].l + st[index].r) / 2;
    st[index].lson = ++st_ptr;
    st[index].rson = ++st_ptr;

    build(l, mid, st[index].lson);
    build(mid, r, st[index].rson);

    st[index].val = max(st[st[index].lson].val, st[st[index].rson].val);
}

void push(int index){
    if(st[index].aTag != 0){
        st[index].val += st[index].aTag;
        if(st[index].l + 1 != st[index].r){
            if(st[st[index].lson].bTag != 0){
                st[st[index].lson].bTag += st[index].aTag;
            }
            else{
                st[st[index].lson].aTag += st[index].aTag;
            }

            if(st[st[index].rson].bTag != 0){
                st[st[index].rson].bTag += st[index].aTag;
            }
            else{
                st[st[index].rson].aTag += st[index].aTag;
            }
        }
    }
    else if(st[index].bTag != 0){
        st[index].val = st[index].bTag;
        if(st[index].l + 1 != st[index].r){
            st[st[index].lson].aTag = 0;
            st[st[index].lson].bTag = st[index].bTag;

            st[st[index].rson].aTag = 0;
            st[st[index].rson].bTag = st[index].bTag;
        }
    }

    st[index].aTag = st[index].bTag = 0;
}

int query(int l, int r, int index){
    push(index);
    if(st[index].l == l && st[index].r == r){
        return st[index].val;
    }
    int mid = (st[index].l + st[index].r) / 2;

    if(l >= mid){
        return query(l, r, st[index].rson);
    }
    else if(r <= mid){
        return query(l, r, st[index].lson);
    }
    else{
        return max(query(l, mid, st[index].lson), query(mid, r, st[index].rson));
    }
}

void setTo(int l, int r, int val, int index){
    push(index);
    if(st[index].l == l && st[index].r == r){
        st[index].aTag = 0;
        st[index].bTag = val;        
        return;
    }

    int mid = (st[index].l + st[index].r) / 2;

    if(l >= mid){
        setTo(l, r, val, st[index].rson);
    }
    else if(mid >= r){
        setTo(l, r, val, st[index].lson);
    }
    else{
        setTo(l, mid, val, st[index].lson);
        setTo(mid, r, val, st[index].rson);
    }

    st[index].val = st[index].bTag;
}

void modify(int l, int r, int val, int index){
    push(index);
    if(st[index].l == l && st[index].r == r){
        if(st[index].bTag != 0){
            st[index].bTag += val;
        }
        else{
            st[index].aTag += val;
        }
        return;
    }

    int mid = (st[index].l + st[index].r) / 2;

    if(l >= mid){
        modify(l, r, val, st[index].rson);
    }
    else if(mid >= r){
        modify(l, r, val, st[index].lson);
    }
    else{
        modify(l, mid, val, st[index].lson);
        modify(mid, r, val, st[index].rson);
    }

    st[index].val = max(st[st[index].lson].val + st[st[index].lson].aTag, st[st[index].rson].val + st[st[index].rson].aTag);
}

void solve(){
    int n, q; cin >> n >> q;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    build(0, n, 0);

    for(int i = 0; i < q; i++){
        int t, l, r, x; cin >> t;
        if(t == 1){
            cin >> l >> r >> x;
            modify(l-1, r, x, 0);

        }
        else if(t == 2){
            cin >> l >> r;
            cout << query(l-1, r, 0) << endl;
        }
        else{
            cin >> l >> r >> x;
            setTo(l-1, r, x, 0);
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