#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

const int N = 12;
int a[N];
int selected[N];
int n;

void go(int id, int selected_count) {
    if (selected_count == 6) {
        for(int i = 0; i < 6; i++){
            cout << selected[i] << " \n"[i == 5];
        }
        return;
    }
    else if (id == n) {
        return;
    }
    selected[selected_count] = a[id];
    go(id + 1, selected_count + 1);
    go(id + 1, selected_count);
}

void solve(int n, int cnt){
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    if(cnt != 0){
    	cout << endl;
	}
    go(0, 0);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int cnt = 0;
    while(1){
        cin >> n;
        if(n == 0){
            return 0;
        }
        solve(n, cnt);
        cnt++;
    }
}
