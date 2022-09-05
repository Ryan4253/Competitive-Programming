#include<iostream> 
using namespace std;
int main(){
	int a, b; cin >> a >> b;
	int score = 0;
	
	if(a >= 60 || (a+b)/2 >= 60){
		score ++;
	}
	if(b >= 60 || (a+b)/2 >=60){
		score ++;
	}
	
	cout << score << endl;
}

