#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

int solve(int n){
	ll temp;
    priority_queue<ll, vector<ll>, greater<ll> > v; 
	for(int i = 0; i < n; i++){
		cin >> temp;
        v.push(temp);
	}
    ll totalcost = 0;
    ll cost = 0;
    for(int i = 0; i < n-1; i++){
        cost += v.top();
        v.pop();
        cost += v.top();
        v.pop();
        v.push(cost);
        totalcost += cost;
        cost = 0;
    }
    
    cout << totalcost << endl;
	
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	while(1){
		cin >> t;
		if(t == 0){
			break;
		}
		else{
			solve(t);
		}
    }
}
