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
	Node* pre;
	Node* nxt;

	Node(){
		val = -1;
		pre = NULL;
		nxt = NULL;
	}
	Node(int n){
		val = n;
		pre = NULL;
		nxt = NULL;
	}
};

const int N = 100 + 5;

Node* head[N];
Node* tail[N];

void init(int n){
	for(int i = 1; i <= n; i++){
		head[i] = new Node();
		tail[i] = new Node();
		head[i]->nxt = tail[i];
		tail[i]->pre = head[i];
	}
}

void add(int i, int id){
	Node* last = tail[i]->pre;
	Node* n = new Node(id);
	last->nxt = n;
	n->nxt = tail[i];
	tail[i]->pre = n;
	n->pre = last;
}

void leave(int i){
	if(head[i]->nxt == tail[i]){
		cout << "queue " << i << " is empty!" << endl;
	}
	else{
		Node* first = (head[i]->nxt)->nxt;
		first->pre = head[i];
		head[i]->nxt = first;
	}
}

void join(int j, int i){
	if(head[j]->nxt == tail[j]){
		return;
	}

	Node* jfirst = head[j]->nxt;
	Node* jlast = tail[j]->pre;
	Node* ilast = tail[i]->pre;

	ilast->nxt = jfirst;
	jfirst->pre = ilast;
	jlast->nxt = tail[i];
	tail[i]->pre = jlast;

	head[j]->nxt = tail[j];
	tail[j]->pre = head[j];
}

void output(int i){
	Node* curr = head[i]->nxt;
	if(curr == tail[i]){
		cout << " empty";
		return;
	}

	while(curr != tail[i]){
		cout << " " << curr->val;
		curr = curr->nxt;
	}
}

void solve(){
	int n, m; cin >> n >> m;
	init(n);

	for(int i = 0; i < m; i++){
		string s; cin >> s;
		if(s == "ADD"){
			int a, b; cin >> a >> b;
			add(a, b);
		}
		else if(s == "JOIN"){
			int a, b; cin >> a >> b;
			join(a, b);
		}
		else{
			int a; cin >> a;
			leave(a);
		}
	}

	for(int i = 1; i <= n; i++){
		cout << "queue " << i << ":";
		output(i);
		cout << endl;
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
