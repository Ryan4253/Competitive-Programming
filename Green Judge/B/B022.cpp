#include<iostream>
using namespace std;

int cnt;
int f(int n) {
	cnt +=1;
    if (n == 0) return 0;
    else if (n == 1) return 1;
    else return f(n - 1) + f(n - 2);
}

int main(){
	int n; cin >> n;
	int solution = 0;
	solution = f(n);
	
	cout << solution << " " << cnt << endl;
	
}


