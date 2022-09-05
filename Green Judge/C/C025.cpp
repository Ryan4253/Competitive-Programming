#include<iostream>
using namespace std;
int main(){
	string a, b; cin >> b >> a;
	int n; n = a.size();
	
	int score = 0, combo = 0, maxcombo = 0, soul = 0;
	for(int i = 0; i < n; i++){
		if(b[i] != '-' && a[i] == b[i]){
			combo ++;
			soul ++;
			score += combo * 100;
		}
		
		else if (b[i] != '-' && a[i] != b[i]){
			if(combo > maxcombo){
				maxcombo = combo;
			}
			combo = 0;
			soul = soul - 3;
			if(soul < 0){
				soul = 0;
			}
		}
		if(combo > maxcombo){
			maxcombo = combo;
		}
		
	}
	cout << score << " " << maxcombo << " " << soul << endl;
}

