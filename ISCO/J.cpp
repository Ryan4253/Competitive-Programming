#include<bits/stdc++.h>
using namespace std;

const int N = 105;
vector<int> v[N];

void solve(){
    int n; cin >> n;
    for(int i = 1; i <= n * n; i++){
        v[(i-1) % n].push_back(i);
    }


    for(int i = 1; i < n; i+=2){
        for(int j = 0; j < n/2; j++){
            swap(v[j][i], v[n-j-1][i]);
        }
    }

    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int n = 1; //cin >> n;
    for(int i = 0; i < n; i++){
        solve();
    }
}