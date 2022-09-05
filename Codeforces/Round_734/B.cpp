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
        string s; cin >> s;
        int val = s.size();
        int cnt[26];

        for(int i = 0; i < 26; i++){
            cnt[i] = 0;
        }

        for(int i = 0; i < s.size(); i++){
            cnt[s[i]-'a']++;
        }

        for(int i = 0; i < 26; i++){
            if(cnt[i] > 2){
                val = val - cnt[i] + 2;
            }
        }
        cout << val / 2 << endl;


    }

    int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n = 1; cin >> n;
    while(n--){
        solve();
    }
    }