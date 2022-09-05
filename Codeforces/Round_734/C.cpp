#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define F first;
#define S second;

const int N = 200000 + 5;
int a[N];
int cnt[N];
int color[N];
int used[N];
int sol[N];

bool cmp(pii a, pii b){
    if(a.second > b.second){
        return false;
    }
    else if(b.second > a.second){
        return true;
    }
    else{
        if(a.first > b.first){
            return false;
        }
        else{
            return true;
        }
    }
}


void solve(){
    int n, k; cin >> n>> k;
    vector<pii> v;
    for(int i = 0; i < n; i++){
        int temp; cin >> temp;
        v.pb(mp(i, temp));
    }

    sort(v.begin(), v.end(), cmp);

    for(int i = 0; i < n; i++){
        cnt[v[i].second]++;
    }

    int curr_color = 0;
    for(int i = 0; i < v.size(); i++){
        if(used[v[i].second] < k){
            color[v[i].first] = curr_color+1;
            used[v[i].second]++;
            curr_color ++;
            curr_color %= k;
        }
        else{
            color[v[i].first] = 0; 
        }
    }

    int zero = 0;
    for(int i = 0; i < n; i++){
        if(color[v[i].first] == 0){
            zero++;
        }
    }

    int remove = (n - zero) % k;
    int removed = 0;
    int i = 0;
    while(removed != remove){
        if(color[v[i].first] != 0){
            color[v[i].first] = 0;
            removed++;
        }
        i++;
    }

    for(int i = 0; i < n; i++){
        sol[v[i].first] = color[v[i].first];
    }
    
    for(int i = 0; i < n; i++){
        cout << sol[i] << " ";
    }
    cout << endl;

    for(int i = 0; i <= n; i++){
        cnt[i] = 0;
        used[i] = 0;
        color[i] = 0;
        sol[i] = 0;
        a[i] = 0;
    }
    v.clear();
}

/*
void solve(){
    int n, k; cin >> n>> k;
    vector<pii> v;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        cnt[a[i]]++;
        if(cnt[a[i]] <= k){
            v.pb(mp(i, a[i]));
        }
    }
    
    for(int i = 0; i < v.size(); i++){
        cout << v[i].first << " " << v[i].second << endl;
    }
    
    int curr_color = 0;
    sort(v.begin(), v.end(), cmp);

    for(int i = 0; i < v.size(); i++){
        color[i] = curr_color+1;
        curr_color++;
        curr_color %= k;
    }

    int zero = n - v.size();
    int rem = (n-zero) % k;

    for(int i = 0; i < rem; i++){
        color[i] = 0;
    }

    for(int i = 0; i < v.size(); i++){
        sol[v[i].first] = color[i];
    }

    for(int i = 0; i < n; i++){
        cout << sol[i] << " ";
    }
    cout << endl;

    for(int i = 0; i <= n; i++){
        cnt[i] = 0;
        used[i] = 0;
        color[i] = 0;
        sol[i] = 0;
        a[i] = 0;
    }


}
*/

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n = 1; cin >> n;
  while(n--){
    solve();
  }
}