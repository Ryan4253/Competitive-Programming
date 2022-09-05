#include<bits/stdc++.h>
using namespace std;

#define ll long long
//#define endl '\n'
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define F first;
#define S second;

const int N = 200000 + 5;
const int P = 20;
int n = 0;
int cost[N];

int anc[N][P];
ll int dist[N][P];

vector<int> v[N];
ll int depth[N];
int sol[N];

int st_ptr = 0;

struct Node{
    ll int val = 0;
    int l, r;
    int lson, rson;
    ll int tag = 0;
};

Node st[2 * N];


void build(int l, int r, int index){
    st[index].l = l, st[index].r = r;
    if(l + 1 == r){
        return;
    }
    
    int mid = (l + r) / 2;
    st[index].lson = ++st_ptr;
    st[index].rson = ++st_ptr;
    build(l, mid, st[index].lson);
    build(mid, r, st[index].rson);
}

void push(int index){
    st[index].val += (st[index].r - st[index].l) * st[index].tag;
    if(st[index].l + 1 != st[index].r){
        st[st[index].lson].tag += st[index].tag;
        st[st[index].rson].tag += st[index].tag;
    }
    st[index].tag = 0;
}

void modify(int l, int r, int index, int val){
    if(l == r){
        return;
    }
    push(index);
    if(st[index].l == l && st[index].r == r){
        st[index].tag += val;
        return;
    }
    
    int mid = (st[index].l + st[index].r) / 2;
    if(l >= mid){
        modify(l, r, st[index].rson, val);
    }
    else if(mid >= r){
        modify(l, r, st[index].lson, val);
    }
    else{
        modify(l, mid, st[index].lson, val);
        modify(mid, r, st[index].rson, val);
    }
    
    push(st[index].lson);
    push(st[index].rson);
    
    st[index].val = max(st[st[index].lson].val, st[st[index].rson].val);
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
    else if(mid >= r){
        return query(l, r, st[index].lson);
    }
    else{
        return query(l, mid, st[index].lson) + query(mid, r, st[index].rson);
    }
}

int query(int target){
    return query(target, target+1, 0);
}

void buildTable(){
    for(int i = 1; i < P; i++){
        for(int j = 1; j <= n; j++){
            anc[j][i] = anc[anc[j][i-1]][i-1];
            dist[j][i] = dist[j][i-1] + dist[anc[j][i-1]][i-1];
        }
    }
}

void dfs(int now, int dep){
    depth[now] = dep;
    int sNow = now;
    for(int i = P-1; i >= 0; i--){
        if(dist[sNow][i] <= cost[now]){
            cost[now] -= dist[sNow][i];
            sNow = anc[sNow][i];
        }
    }    
    
    modify(depth[sNow], dep, 0, 1);
    //cout << "MODIFY" << endl;
    
    for(int i = 0; i < v[now].size(); i++){
        dfs(v[now][i], dep+1);
    }
    
    sol[now] = query(dep);
    modify(dep, dep + 1, 0, -sol[now]);
}

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> cost[i];
    }
    anc[1][0] = 1; dist[1][0] = 0; 
    for(int i = 2; i <= n; i++){
        cin >> anc[i][0] >> dist[i][0];
    }
    
    for(int i = 2; i <= n; i++){
        v[anc[i][0]].pb(i);
    }
    
    build(0, n, 0);
    buildTable();
    dfs(1, 0);
    
    for(int i = 1; i <= n; i++){
        cout << sol[i] << " ";
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