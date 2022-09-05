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
            a[i] -= i;
        }

        sort(a, a + n);
        /*
        for(int i = 0; i < n; i++){
            cout << a[i] << " ";
        }
        cout << endl;
        */
        ll int sol = 0;
        ll int cnt = 1;

        for(int i = 1; i < n; i++){
            if(a[i] == a[i-1]){
                cnt++;
            }
            else{
                sol += (cnt) * (cnt-1) / 2;
                cnt = 1;
            }
        }

        sol += (cnt) * (cnt-1) / 2;

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