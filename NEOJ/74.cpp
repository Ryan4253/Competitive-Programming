#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back

void solve(){
	int n; cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	} 
	
	int length = 0;
	int increment = 0; // 1 smaller 0 larger
	int prevalue;
	int i = 0;
	
	while(1){
		if(a[i] > a[i+1]){
			incrememnt = 1;
			prevalue = a[i];
			break;
		}
		else if(a[i] < a[i+1]){
			increment = 0;
			prevalue = a[i];
			break;
		}
		if(a[i] == a[i+1]){
			i++;
		}
	}
	
	
	
	for(int i = 0; i < n; i++){
		
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
}

