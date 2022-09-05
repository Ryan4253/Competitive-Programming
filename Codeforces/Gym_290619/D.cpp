#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;

const int N = 200000 + 5;
int agi[N];
int l[N];
int r[N];
int d[N];
vector<pair<int, int> > v;


bool check(int time, int k, int minagi, int n){
	for(int i = 0; i < k; i++){
        if(d[i] > minagi){
            v.pb(make_pair(l[i], r[i]));
        }
    }
    
    sort(v.begin(), v.end());
    
    int union_length = 0;
    int current_left = -1, current_right = -2;
    
    for(int i = 0; i < v.size(); i++){
        if(v[i].first <= current_right){
            current_left = min(v[i].first, current_left);
            current_right = max(v[i].second, current_right);
        }
        else{
            union_length += current_right - current_left + 1;
            current_left = v[i].first;
            current_right = v[i].second;
        }
    }
    
    union_length += current_right - current_left + 1;
    
    if(union_length * 2 + n + 1 > time){
        return false;
    }
    else{
        return true;
    }
} 

 
void solve(){
	int m, n, k, t; cin >> m >> n >> k >> t;
    
    for(int i = 0; i < m; i++){
        cin >> agi[i];
    }
    
    for(int i = 0; i < k; i++){
        cin >> l[i] >> r[i] >> d[i];
    }
    
    sort(agi, agi + m, greater<int>());
    
    int left = -1; int right = m;
    
    while(left + 1 != right){
        int mid = (left + right) / 2;
        if(check(t, k, agi[mid], n)){
            left = mid;
        }
        else{
            right = mid;
        }
        v.clear();
    }
    
    cout << left + 1 << endl;

    
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
    solve();
}
