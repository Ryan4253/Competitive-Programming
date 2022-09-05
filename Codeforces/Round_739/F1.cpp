#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define F first;
#define S second;

int count_digit(int number) {
   return int(log10(number) + 1);
}

bool check(int a[], int b[], int len){
    for(int i = 0; i < len; i++){
        if(a[i] > b[i]){
            return false;
        }
        else if(a[i] < b[i]){
            return true;
        }
    }

    return true;
}

int generate(int a[], int val1, int val2, int len){
    int sol = 0;
    bool ok = false;
    if(val1 > val2){
        swap(val1, val2);
    }

    for(int i = 0; i < len; i++){
        
        sol *= 10;
        if(ok){
            sol += val1;
        }
        else if(a[i] > val1 && a[i] > val2){
            return -1;
        }
        else if(val1 > a[i]){
            sol += val1;
            ok = true;
        }
        else if(val1 == a[i]){
            sol += val1;
        }
        else if(val2 > a[i]){
            sol += val2;
            ok = true;
        }
        else if(val2 == a[i]){
            sol += val2;
        }
    }

    return sol;
}

void solve(){
    int n, k; cin >> n >> k;

    if(k == 2){
        if(n == 9){
            cout << 10 << endl;
            return;
        }
        else if(n == 99){
            cout << 100 << endl;
            return;
        }
        else if(n == 999){
            cout << 1000 << endl;
            return;
        }
        else if(n == 9999){
            cout << 10000 << endl;
            return;
        }
        else if(n == 99999){
            cout << 100000 << endl;
            return;
        }
        else if(n == 999999){
            cout << 1000000 << endl;
            return;
        }
        else if(n == 9999999){
            cout << 10000000 << endl;
            return;
        }
        else if(n == 99999999){
            cout << 100000000 << endl;
            return;
        }
        else if(n == 999999999){
            cout << 1000000000 << endl;
            return;
        }
    }

    int len = count_digit(n);
    int a[len], b[len];

    int tempn = n;
    for(int i = len-1; i >= 0; i--){
        a[i] = tempn % 10;
        tempn /= 10;
    }

    if(k == 1){
        for(int i = 0; i < len; i++){
            b[i] = a[0];
        }
        if(check(a, b, len)){
            for(int i = 0; i < len; i++){
                cout << b[i];
            }
            cout << endl;
        }
        else{
            for(int i = 0; i < len; i++){
                cout << b[i]+1;
            }
            cout << endl;
        }
    }
    else{
        int sol = 2147483647;
        for(int i = 1; i < 10; i++){
            for(int j = 0; j < 10; j++){
                if(i == j){
                    continue;
                }
                int wasd = generate(a, i, j, len);
                if(wasd != -1){
                    sol = min(sol, wasd);
                }
            }
        }
        cout << sol << endl;
    }
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n = 1; cin >> n;
  while(n--){
    solve();
  }

}