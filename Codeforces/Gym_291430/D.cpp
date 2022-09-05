#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

const int N = 1000 + 5;
int x[N];
int y[N];

void solve(){
	int n; cin >> n;
    vector<int> v[2][2];
    int temp1, temp2;
    
    for(int i = 0; i < n; i++){
    	
        cin >> temp1;
        temp1 += 1000000;
        cin >> temp2; 
        temp2 += 1000000;
        
        x[i] = temp1;
        y[i] = temp2;
    }
    int ans = 0;
    while(1){
    	v[1][1].clear(); v[0][0].clear(); v[0][1].clear(); v[1][0].clear();
        for(int i = 0; i < n; i++){
            v[x[i] % 2][y[i] % 2].pb(i);
        }
        int a = v[1][1].size() + v[0][0].size();
        if(1 <= a && a <= n-1){
            cout << a << endl;
            for(int i = 0; i < v[1][1].size(); i++){
                cout << v[1][1][i]+1 << " ";
            }
            for(int i = 0; i < v[0][0].size(); i++){
                cout << v[0][0][i]+1 << " "; 
            }
            return;
        }
        
        if(a == 0){
            if(v[0][1].size() > 0 && v[1][0].size() > 0){
                cout << v[0][1].size() << endl;
                for(int i = 0; i < v[0][1].size(); i++){
                    cout << v[0][1][i]+1 << " ";
                }
                return;
            }
            else{
                for(int i = 0; i < n; i++){
                    x[i] /= 2;
                    y[i] /= 2;
                }
            }
        }
        
        if(a == n){
            if(v[1][1].size() > 0 && v[0][0].size() > 0){
                cout << v[1][1].size() << endl;
                for(int i = 0; i < v[1][1].size(); i++){
                    cout << v[1][1][i]+1 << endl;
                }
                return;
            }
            else{
                for(int i = 0; i < n; i++){
                    x[i] /= 2;
                    y[i] /= 2;
                }
            }
        }
        
    }
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
    solve();
}
