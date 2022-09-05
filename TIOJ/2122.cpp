	#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

const int N = 100000 + 5;
const int K = 315;

struct query{
    int l, r;
    int block;
    int pos;
    int ans;
    
    query(int _l, int _r, int _pos){
        l = _l, r = _r, pos = _pos;
        block = l / K;
    }
};


int a[N];
int cnt[N];
int cnt2[N];
int curMax = 0;
vector<query> v;

int curL = 1, curR = 0;

// [1, 0]

//void clear(int n){for(int i = 0; i < n; i++){a[i] = 0;}}

bool cmp(const query& q1, const query& q2){
    if(q1.block != q2.block){
        return q1.block < q2.block;
    }
    else{
        return q1.r < q2.r;
    }
    
}

bool cmp2(const query& q1, const query& q2){
    return q1.pos < q2.pos;
}

void add(int x){
    cnt2[cnt[x]]--;
    cnt[x]++;
    cnt2[cnt[x]]++;
    
    if(cnt[x] > curMax){
        curMax = cnt[x];
    }
}

void del(int x){
    if(cnt[x] == curMax){
        if(cnt2[cnt[x]] <= 1){
            curMax--;
        }
    }
    
    cnt2[cnt[x]]--;
    cnt[x]--;
    cnt2[cnt[x]]++;
    
    /*
    if (cnt2[curMax] == 0) --curMax;
    */
    
    
}

void calc(int i){
    query &q = v[i];
    
    while(q.l < curL){
        add(a[curL-1]);
        curL--;
    }
    
    while(q.r > curR){
        add(a[curR+1]);
        curR++;
    }
    
    while(q.l > curL){
        del(a[curL]);
        curL++;
    }
    
    while(q.r <  curR){
        del(a[curR]);
        curR--;
    }
    
    q.ans = curMax;
}

void solve(){
	int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    
    for(int i = 0; i < q; i++){
        int l, r; cin >> l >> r;
        v.pb({l, r, i});
    }
    
    sort(v.begin(), v.end(), cmp);
    
    for(int i = 0; i < v.size(); i++){
        calc(i);
    }
    
    sort(v.begin(), v.end(), cmp2);
    
    for(int i = 0; i < v.size(); i++){
        cout << v[i].ans << endl;
    }
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}