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
    Node* l;
    Node* r;     
}; 

//builds a new node
Node* newNode(int n){ 
    Node* node = new Node();
    
    node->val = n;
    node->l = NULL;
    node->r = NULL;
    
    return node;
}

Node* insert(Node* node, int x){
    if(node == NULL){
        return newNode(x);
    }
    
    if(x < node->val){
        node->l = insert(node->l, x);
    }
    else{
        node->r = insert(node->r, x);
    }
    
    return node;
}

void output(Node* root){
    if(root == NULL){
        return;
    }
    output(root->l);    
    output(root->r); 
    cout << root->val << endl;
}


void solve(){
    int n; cin >> n;
    Node* head = NULL;
    head = insert(head, n);
    while(cin >> n){
        insert(head, n);
    }
    output(head);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n = 1;
    while(n--){
        solve();
    }
}
