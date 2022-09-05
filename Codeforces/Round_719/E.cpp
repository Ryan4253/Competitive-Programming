#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define F first;
#define S second;

vector<int> sheep;

ll int calcCost(int center){
    ll int sol = 0;
    ll int lcnt = 0, rcnt = 0;
    bool crossCenter = false;
    for(int i = 0; i < sheep.size(); i++){
        if(sheep[i] == sheep[center]){
            crossCenter = true;
            continue;
        }
        sol += abs(sheep[i]-sheep[center])-1;
        if(!crossCenter){
            lcnt++;
        }
        else{
            rcnt++;
        }
    }
    //cout << "TEMP" << sol << endl;

    sol -= ((lcnt * (lcnt-1) / 2)+(rcnt * (rcnt-1) / 2));

    return sol;
}

void solve(){
  int n; cin >> n;
  string s; cin >> s;
    for(int i = 0; i < n; i++){
        if(s[i] == '*'){
            sheep.pb(i);
        }
    }

    if(sheep.size() == 0){
        cout << 0 << endl;
        return;
    }

    if(sheep.size() % 2 == 0){
        cout << min(calcCost(sheep.size()/2), calcCost(sheep.size()/2-1)) << endl;
    }
    else{
        cout << calcCost(sheep.size()/2) << endl;
    }


    sheep.clear();
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n = 1; cin >> n;
  while(n--){
    solve();
  }
}