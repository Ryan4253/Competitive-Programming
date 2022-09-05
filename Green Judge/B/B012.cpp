#include<iostream>
using namespace std;
int main(){
	string s; cin >> s;
	int x = 0;
    int ans = 0;
	x = s.size();
    
    int a[144];
    a['I'] = 1;
    a['V'] = 5;
    a['X'] = 10;
    a['L'] = 50;
    a['C'] = 100;
	a['D'] = 500;
    a['M'] = 1000;
	for(int i = 0; i < x; i++){
        ans = ans + a[s[i]];
        
        if(i > 0){
            if(a[s[i]]>a[s[i-1]]){
                ans = ans - 2 * a[s[i-1]];
            }
        }
    }
    cout << ans << endl;
}
