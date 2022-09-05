#include<iostream>
using namespace std;

void f(int n, int start, int goal, int mid){
	if(n == 1){
		cout << "Ring " << n << " from " << start << " to " << goal << endl;
		return;
	}
	f(n-1, start, mid, goal); 
	cout << "Ring " << n << " from " << start << " to " << goal << endl;
	f(n-1, mid, goal, start);
	
}

int main(){
	int n; cin >> n;
	f(n, 1, 3, 2);
}
