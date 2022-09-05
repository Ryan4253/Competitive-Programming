#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define F first;
#define S second;

const int N = 200000;
int a[N][6];
int n;

int compute(int val){
    vector<int> v;
    for(int i = 0; i < n; i++){
        v.pb(a[i][val] - (a[i][5] - a[i][val]));
    }

    for(int i = 0; i < n; i++){
      //  cout << v[i] << " ";
    }
    //cout << endl;

    sort(v.begin(), v.end(), greater<int>());
    
    int sum = 0;
    int cnt = 0;
    /*
    for(int i = 0; i < n; i++){
        cout << v[i] << " ";
    }
    cout << endl;
    */
    for(int i = 0; i < n; i++){
        if(sum + v[i] > 0){
            sum += v[i];
            cnt++;
        }
    }
    return cnt;
}

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        for(int j = 0; j < s.size(); j++){
            a[i][s[j]-'a']++;
        }
        a[i][5] = a[i][0] + a[i][1] + a[i][2] + a[i][3] + a[i][4]; 
    }
    /*
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 6; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    */
    


    int sol = 0;

    for(int i = 0; i < 5; i++){
        sol = max(sol, compute(i));
    }

    cout << sol << endl;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 6; j++){
            a[i][j] = 0;
        }
    }


}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n = 1; cin >> n;
  while(n--){
    solve();
  }
}