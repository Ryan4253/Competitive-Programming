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

void solve(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int sum = accumulate(a, a + n, 0);

    if(sum % n != 0){
        cout << -1 << endl;
        return;
    }

    int avg = sum / n;
    int sol = 0;
    for(int i = 0; i < n; i++){
        if(a[i] > avg){
            sol++;
        }
    }
    cout << sol << endl;

    for(int i = 0; i < n; i++){
        a[i] = 0;
    }

}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n = 1; cin >> n;
  while(n--){
    solve();
  }
}