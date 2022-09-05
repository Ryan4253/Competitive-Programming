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
};

const int N = 200000 + 5;
const int BASE = 107;
const int MOD = 1000000007;

int a[N];

ll power(int a, int b){
    if(b == 0){
        return 1;
    }
    if(b == 1){
        return a;
    }
    ll result = power(a, b/2);
    if(b % 2 == 0){

        return (result * result) % MOD;
    }
    else{
        return (result * result * a) % MOD;
    }
}


struct SegmentTree{
    int st_ptr = 0;
    Node st[2 * N];

    void build(int l, int r, int index){
        st[index].l = l; st[index].r = r;
        if(l + 1 == r){
            st[index].val = (a[l]);
            return;
        }

        int mid = (st[index].l + st[index].r) / 2;
        st[index].lson = ++st_ptr;
        st[index].rson = ++st_ptr;

        build(l, mid, st[index].lson);
        build(mid, r, st[index].rson);

        st[index].val = (st[st[index].lson].val + st[st[index].rson].val) % MOD;
    }

    void modify(int pos, int nVal, int index){
        if(st[index].l + 1 == st[index].r){
            st[index].val = nVal;
            return;
        }

        int mid = (st[index].l + st[index].r) / 2;

        if(pos >= mid){
            modify(pos, nVal, st[index].rson);
        }
        else{
            modify(pos, nVal, st[index].lson);
        }

        st[index].val = (st[st[index].lson].val + st[st[index].rson].val) % MOD;
    }

    int query(int l, int r, int index){
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
            return (query(l, mid, st[index].lson) + query(mid, r, st[index].rson)) % MOD;
        }
    }
};

SegmentTree s1;
SegmentTree s2;

void solve(){
    int n, q; cin >> n >> q;
    string s; cin >> s;

    for(int i = 0; i < n; i++){
        a[i] = (s[i] * power(BASE, i)) % MOD;
    }
    s1.build(0, n, 0);
    
    for(int i = 0; i < n; i++){
        a[i] = (s[i] * power(BASE, n-i-1)) % MOD;
    }

    s2.build(0, n, 0);

    for(int i = 0; i < q; i++){
        int type; cin >> type;
        if(type == 1){
            int l, r; cin >> l >> r;
            l--;
            int mid = (l + r) / 2;

            ll int v1 = s1.query(l, mid, 0);
            ll int v2;
            int diff;
            if((r - l) % 2 == 0){
                v2 = s2.query(mid, r, 0);
                diff = mid-l;
            } 
            else{
                v2 = s2.query(mid+1, r, 0);
                diff = mid-l+1;
            }

            v1 = (v1 * diff) % MOD;

            if(v1 == v2){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
        else{
            int p; char c; cin >> p >> c;
            ll int c1 = c * power(BASE, p-1);
            ll int c2 = c * power(BASE, n-p);
            s1.modify(p, c1, 0);
            s2.modify(p, c2, 0);
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