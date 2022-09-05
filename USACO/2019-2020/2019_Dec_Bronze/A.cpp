#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

const int N = 20 + 5;
int a[N][N];

bool check(int x, int y, int k){
    bool state = a[0][x] > a[0][y];
    bool flag = true;
    for(int i = 1; i < k; i++){
        if(state != (a[i][x] > a[i][y])){
            flag = false;

        }
    }
    
    return flag;
}

void solve(){
    int k, n; cin >> k >> n;
    for(int i = 0; i < k; i++){
        for(int j = 0; j < n; j++){
            int x; cin >> x;
            a[i][x-1] = j; 
        }
    }
    
    int sol = 0;
    
    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < n; j++){

            if(i != j && i < j && check(i, j, k)){
                sol++;
            }
            

        }
    }
    
    cout << sol << endl;
}

int main(){
    if(fopen("gymnastics.in", "r")){
        freopen("gymnastics.in", "r", stdin);
        freopen("gymnastics.out", "w", stdout);
    }
    ios::sync_with_stdio(0); cin.tie(0);

    solve();
}