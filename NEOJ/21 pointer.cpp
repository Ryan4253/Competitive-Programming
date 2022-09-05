#include<bits/stdc++.h>
using namespace std;

//#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

struct Node{
	int val;
	Node* nxt;
	Node* pre;
	
	Node(){
		val = -1;
		nxt = NULL;
		pre = NULL;
	} 
};

Node* player[100000 + 5];
Node* head = new Node();
Node* tail = new Node();

void build(int n){
	for(int i = 1; i <= n; i++){
		player[i] = new Node();
		player[i]->val = i;
	}
	if(n == 1){
		head->nxt = player[1];
		tail->pre = player[1];
		player[1]->nxt = tail;
		player[1]->pre = head;
	}
	else{
		for(int i = 1; i <= n; i++){
			if(i == 1){
				head->nxt = player[1];
				player[i]->pre = head;
				player[i]->nxt = player[2];
			}
			else if(i == n){
				player[i]->nxt = tail;
				player[i]->pre = player[i-1];
				tail->pre = player[i];
			}
			else{
				Node* prev = player[i-1];
				Node* next = player[i+1];
				player[i]->nxt = next;
				player[i]->pre = prev;	
			}
		}
	}

}

void remove(int id){
	Node* prev = player[id]->pre;
	Node* next = player[id]->nxt;
	prev->nxt = next;
	next->pre = prev;
}

void speed(int id){
	if(head->nxt == player[id]){
		return;
	}
	Node* next= player[id]->pre;
	Node* nextnext = next->pre;
	Node* prev = player[id]->nxt;
	
	nextnext->nxt = player[id];
	player[id]->pre = nextnext;
	player[id]->nxt = next;
	next->pre = player[id];
	next->nxt = prev;
	prev->pre = next;
} 

void output(){
	Node* start = head->nxt;
	if(start == tail){
		return;
	}
	
	while((start->nxt) != tail){
		cout << start->val << " ";
		start = start->nxt;
	}
	cout << start->val << endl;
	
}

void solve(){
	int n, m; cin >> n >> m;
	build(n);

	int x, y;
	
	for(int i = 0; i < m; i++){
		cin >> x >> y;
		if(x == 0){
			remove(y);
		}
		else{
			speed(y);
		}
	}
	output();
	
}

int main(){
	//ios::sync_with_stdio(0); cin.tie(0);
	int n = 1;
	while(n--){
		solve();
 	}
}

