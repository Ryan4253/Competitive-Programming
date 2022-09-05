#include<iostream>
using namespace std;
int main(){
	int x = 0, y = 0, flag = 1;
	string a;//target
	string b;//monkey
	cin >> a >> b;
	x = a.size();
	y = b.size();
	int j = 0;
    string ans = "YES";
    
	for(int i = 0; i < x; i++){
        for(; j < y; j++){
            if(a[i] == b[j]){
                flag = 1;
                j = j + 1;
                break;
            }
            else if(a[i] != b[j]){
                flag = 0;
            }
        }
        if(flag == 0){
            ans = "NO";
        }
    } 
    cout << ans << endl;
}
