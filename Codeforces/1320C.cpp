#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define F first;
#define S second;

struct Weapon{
    int atk, cost;
};

struct Armor{
    int def, cost;
};

struct Monster{
    int atk, def, cost;
};

struct Node{
    ll int val;
    int l, r;
    int lson, rson;
    ll int tag;
};

const int N = 200000 + 5;
vector<Weapon> weapon;
vector<Armor> armor;
vector<Monster> monster;
vector<int> armorDef;
Node st[2 * N];
int st_ptr = 0;

bool cmpWeapon(const Weapon& a, const Weapon& b){
    return a.atk < b.atk;
}

bool cmpArmor(const Armor& a, const Armor& b){
    return a.def < b.def;
}

bool cmpMonster(const Monster& a, const Monster& b){
    return a.def < b.def;
}

void build(int l, int r, int index){
    st[index].l = l, st[index].r = r;
    if(l + 1 == r){
        st[index].val = -armor[l].cost;
        st[index].tag = 0;
        return;
    }
    
    int mid = (l + r) / 2;
    st[index].lson = ++st_ptr;
    st[index].rson = ++st_ptr;
    build(l, mid, st[index].lson);
    build(mid, r, st[index].rson);
    
    st[index].val = max(st[st[index].lson].val, st[st[index].rson].val);
}

void push(int index){
    st[index].val += st[index].tag;
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
    
    st[index].val = max(st[st[index].lson].val + st[st[index].lson].tag, st[st[index].rson].val + st[st[index].rson].tag);
}

void solve(){
    int n, m, p; cin >> n >> m >> p;
    weapon.resize(n); armor.resize(m); monster.resize(p);
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        weapon[i].atk = a;
        weapon[i].cost = b;
    }

    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        armor[i].def = a;
        armor[i].cost = b;
    }

    for(int i = 0; i < p; i++){
        int a, b, c; cin >> a >> b >> c;
        monster[i].def = a;
        monster[i].atk = b;
        monster[i].cost = c;
    }

    sort(weapon.begin(), weapon.end(), cmpWeapon);
    sort(armor.begin(), armor.end(), cmpArmor);
    sort(monster.begin(), monster.end(), cmpMonster);

    for(int i = 0; i < m; i++){
        armorDef.pb(armor[i].def);
    }

    build(0, m, 0);
    ll int sol = -2147483648;
    int prevMonster = 0;

    for(int i = 0; i < n; i++){
        //cout << "PREVMONSTER " << prevMonster << endl;
        for(int j = prevMonster; j < p; j++){
            if(monster[j].def < weapon[i].atk){
                prevMonster++;
                int start = upper_bound(armorDef.begin(), armorDef.end(), monster[j].atk) - armorDef.begin();
                modify(start, m, 0, monster[j].cost);
            }
            else{
                break;
            }
        }
        push(0);
        sol = max(sol, st[0].val - weapon[i].cost);
    }
    //cout << st[0].val << " " << st[0].tag << endl;
    cout << sol << endl;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n = 1;
  while(n--){
    solve();
  }
}