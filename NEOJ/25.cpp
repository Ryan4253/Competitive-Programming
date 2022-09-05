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
    Node* pre;
    
    Node(){
        val = -1;
        nxt = NULL;
    	pre = NULL;
    }
};

Node* head[102];
Node* tail[102];

void initialize(){
	for(int i = 0; i < 102; i++){
		head[i] = new Node();
		tail[i] = new Node();
		head[i]->nxt = tail[i];
		tail[i]->pre = head[i];
	}
}

void add(int i, int id){
	Node* otaku = new Node();
	Node* old = tail[i]->pre;
	
	otaku->val = id;
	otaku->nxt = tail[i];
	otaku->pre = old;
	old->nxt = otaku;
	tail[i]->pre = otaku;
}

void leave(int i){
	if(head[i]->nxt == tail[i]){
		cout << "queue " << i << " is empty!" << endl;
	}
	else{
		(head[i]->nxt) = (head[i]->nxt) -> nxt;
		(head[i]->nxt) -> pre = head[i];
	}
}

void join(int i, int j){
	if(head[i]->nxt == tail[i]){
		return;
	}
	
	Node* ifront = head[i]->nxt;
	Node* iback = tail[i]->pre;
	Node* jback = tail[j]->pre;
		
	ifront->pre = jback;
	jback->nxt = ifront;
	iback->nxt = tail[j];
	tail[j]->pre = iback;
	head[i]->nxt = tail[i];
	tail[i]->pre = head[i];
}

void output(int i){
	Node* start = head[i]->nxt;
	cout << "queue " << i << ":";
	
	if(start->nxt == NULL){
		cout << " empty" << endl;
		return;
	}
	else{
		while(start->nxt != NULL){
			cout << " " << start->val;
			start = start->nxt; 
		}
		cout << endl;
	}
}

void solve(){
	initialize();
	
	int n, m; cin >> n >> m;
	string status;
	
	for(int i = 0; i < m	; i++){
		cin >> status;
		int x, y;
		if(status == "ADD"){
			cin >> x >> y;
			add(x, y);
		}	
		else if(status == "LEAVE"){
			cin >> x;
			leave(x);
		}
		else{
			cin >> x >> y;
			join(x, y);
		}
	}
	
	for(int i = 1; i <= n; i++){
		output(i);
	} 
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n = 1; 
	while(n--){
		solve();
 	}
}
