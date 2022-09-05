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

const int N = 100000 + 5;

struct disjoint_set{
    int p[2 * N];
    void initialize(){
        for(int i = 0; i < 2 * N; i++){
            p[i] = i;
        }
    }
    
    int find(int x){
        return p[x] == x ? x : p[x] = find(p[x]);
    }

    void uni(int x, int y){
        p[find(x)] = find(y);
    }
};

struct edge{
    int s, e, cost;
    
    edge(int a, int b, int c){
        s = a, e = b, cost = c;
    };
};

bool cmp(const edge& a, const edge& b){
    return a.cost < b.cost;
}

vector<edge> v;

int Kruskall(){
    ll int sol = 0;
    disjoint_set  st;
    st.initialize();
    
    sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < v.size(); i++){
        if(st.find(v[i].s) == st.find(v[i].e)){
            continue;
        }
        else{
            sol += v[i].cost;
            st.uni(v[i].s, v[i].e);
        }
    }
    
    return sol;
}

void solve(){
	int n; cin >> n;
    for(int i = 0; i < n; i++){
        int c, v1, v2, v3, v4;
        cin >> c >> v1 >> v2 >> v3 >> v4;
        
        v.pb({v1, v2, 0});
        v.pb({v3, v4, 0});
        v.pb({v1, v3, c});
    }
    
    cout << Kruskall() << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}

