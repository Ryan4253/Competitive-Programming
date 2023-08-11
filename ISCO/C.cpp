#include<bits/stdc++.h>
using namespace std;

const int N = 200000 + 5;
vector<int> v[N];

void solve(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int k; cin >> k;
        int temp; cin >> temp;
        v[i].push_back(temp);

        for(int j = 1; j < k; j++){
            cin >> temp;
            if(temp > v[i].back()){
                v[i].push_back(temp);
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int val : v[i]){
            cout << val << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < n; i++){
        v[i].clear();
    }
}

int main(){
    int n = 1; cin >> n;
    for(int i = 0; i < n; i++){
        solve();
    }
}