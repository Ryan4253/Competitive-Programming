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
	Node *_next;
	Node *_pre;
	
	Node(){
		val = 0;
		_pre = NULL;
		_next = NULL;
	} 
};

Node* head = new Node();
Node* tail = new Node();

	
void insert(int n){
	Node* temp = new Node(); 
	temp->val = n;
	temp->_next = head->_next;
	temp->_pre = head;
	(head->_next)->_pre = temp;
	head->_next = temp;
	
}	

void remove(){
	if((head->_next) == tail){
		cout << "empty!" << endl;
	}
	else{
		cout << (tail->_pre)->val << endl;
		((tail->_pre)->_pre)->_next = tail;
		tail->_pre = (tail->_pre)->_pre;
	}
}
	
void solve(){
	head->_next	= tail;
	tail->_pre	= head;
	int n; cin >> n;
	int x, r;
	for(int i = 0; i < n; i++){
		cin >> x;
		if(x == 1){
			cin >> r;
			insert(r);
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

