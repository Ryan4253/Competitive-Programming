#include<iostream>
using namespace std;
int main(){
	int x = 0, y = 0, z = 0;
	string a, b, c;
	int d = 0, e = 0, f = 0;
	cin >> a >> b >> c;
	x = a.size();
    y = b.size();
    z = c.size();

	
	for(int i = 0; i < x; i++){
			if(a[i] >= '0' && a[i] <= '9'){
                d = d * 10 + (a[i]-'0');
			}
	}
    
    for(int i = 0; i < y; i++){
			if(b[i] >= '0' && b[i] <= '9'){
				e = e * 10 + (b[i] - '0');
			}
	}
    
    for(int i = 0; i < z; i++){
			if(c[i] >= '0' && c[i] <= '9'){
				f = f * 10 + (c[i]-'0');
			}
	}
    
    cout << d + e + f << endl;
		
}
