#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

struct Node{
	int val;
	Node* nxt;
	Node(){
		val = 0;
		nxt = NULL;
	}
};

Node* head = new Node();
Node* tail = new Node();

void insert(){
	int n; cin >> n;
	Node* temp = new Node();
	temp->val = n;
	temp->nxt = head->nxt;
	head->nxt = temp;
}

void remove(){
	if(head->nxt == tail){
		cout << "empty!" << endl;
	}
	else{
		cout << (head->nxt)->val << endl;
		head->nxt = (head->nxt)->nxt;
	}
}

void solve(){
	head->nxt = tail;
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		if(x == 1){
			insert();
		}
		else{
			remove();
		}
	}
}

int main(){
	if(fopen("gymnastics.in", "r")){
	    freopen("gymnastics.in", "r", stdin);
	    freopen("gymnastics.out", "w", stdout);
	}
	ios::sync_with_stdio(0); cin.tie(0);
	int n = 1;
	while(n--){
		solve();
 	}
}

