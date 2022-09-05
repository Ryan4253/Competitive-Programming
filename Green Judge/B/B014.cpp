#include<iostream>
using namespace std;
int main(){
    int x = 0,cn = 0, ans = 0;;
    int n[3];
    
    for(int i = 0; i < 3; i++){
    string a;
	getline(cin, a);
	a = a + " ";
    x = a.size();

        for(int j = 0; j < x; j++){
            if(a[j] >= '0' && a[j] <= '9'){
                cn = cn*10 + (a[j]-'0');
            }
            if(a[j] == ' '){
                ans += cn;
                cn = 0;
            }
        }
        n[i] = ans;
        ans = 0;
    }
    if(n[0] >= n[1] && n[0] >= n[2]){
        cout << 1 << " " << n[0] << endl;
    }
    
    if(n[1] >= n[0] && n[1] >= n[2]){
        cout << 2 << " " << n[1] << endl;
    }
    
    if(n[2] >= n[0] && n[2] >= n[1]){
        cout << 3 << " " << n[2] << endl;
    }

}
