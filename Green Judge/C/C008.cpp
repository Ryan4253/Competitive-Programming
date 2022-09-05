#include<iostream>
using namespace std;
int main(){
	int score; cin >> score;
	int newscore = score *4 / 5 + 30;
	
	if(newscore > 100){
		newscore = 100;
	}
	
	cout << newscore << endl;
}

