#include<bits/stdc++.h>
using namespace std;

int nxt[100005];
int	pre[100005];
int val[100005];
	
int main(){
	int n = 0; cin >> n;
	for(int i = 1; i <= n; i++){
		nxt[i] = i + 1;
		pre[i] = i - 1;
		val[i] = i;
	}

	int head = 0; int tail = n + 1;
	nxt[head] = 1; pre[tail] = n;
	
	int x; cin >> x;
	for(int j = 0; j < x; j++){
		int a; cin >> a;
		int b; cin >> b;
		if(a == 0){
			int tmp1 = pre[b];
			int tmp2 = nxt[b];
			nxt[tmp1] = tmp2;
			pre[tmp2] = tmp1;
		}
		else{
			if(pre[b] == head){
				continue;
			}
			int _3 = b, _1 = pre[pre[b]],  _2 = pre[b],  _4 = nxt[b];
			nxt[_3] = _2;
			pre[_3] = _1;
			nxt[_2] = _4;
			pre[_2] = _3;
			nxt[_1] = _3;
			pre[_4] = _2;
		}
		
	}
	cout << nxt[head];
	for(int i = nxt[nxt[head]]; i != tail; i = nxt[i]){
		cout << " " << i;
	}
	cout << endl;
	

}

