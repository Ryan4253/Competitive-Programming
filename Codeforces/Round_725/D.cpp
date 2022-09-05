#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define F first;
#define S second;

void solve(){
    int a, b, k; cin >> a >> b >> k;
    if(k >= 2){
        vector<int> primeA;
        vector<int> primeB;
         while (a%2 == 0){
             primeA.pb(2);
            a = a/2;
        }
        for (int i = 3; i <= sqrt(a); i = i+2){
            while (a%i == 0){
                primeA.pb(i);
                a = a/i;
            }
        }
        if(a > 2){
            primeA.pb(a);
        }

        while(b % 2 == 0){
            primeB.pb(2);
            b = b/2;
        }
        for (int i = 3; i <= sqrt(b); i = i+2){
            while (b%i == 0){
                primeB.pb(i);
                b = b/i;
            }
        }
        if(b > 2){
            primeB.pb(b);
        }


        if(primeA.size() + primeB.size() >= k){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    else{
        int gcd = __gcd(a, b);
        if(gcd == min(a, b) && a != b){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
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